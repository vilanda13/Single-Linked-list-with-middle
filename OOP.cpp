#include <iostream>

using namespace std;

class Buku {
public:
    string judul, pengarang;
    int tahunTerbit;
    Buku* next;
};

Buku* head;
Buku* tail;
Buku* cur;
Buku* newNode;
Buku* del;
Buku* before;

// Create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB) {
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

// Count single linked list
int countSingleLinkedList() {
    cur = head;
    int jumlah = 0;
    while (cur != NULL) {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

// Add first to single linked list
void addFirst(string judul, string pengarang, int tB) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

// Add last to single linked list
void addLast(string judul, string pengarang, int tB) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// Add middle to single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;

    cur = head;
    int nomor = 1;
    while (nomor < posisi - 1 && cur != NULL) {
        cur = cur->next;
        nomor++;
    }

    if (cur != nullptr) {
        newNode->next = cur->next;
        cur->next = newNode;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// Remove first from single linked list
void removeFirst() {
    if (head != NULL) {
        del = head;
        head = head->next;
        delete del;
    } else {
        cout << "List kosong" << endl;
    }
}

// Remove last from single linked list
void removeLast() {
    if (head == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    del = tail;
    cur = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = NULL;
    }

    delete del;
}

// Remove middle from single linked list
void removeMiddle(int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    int nomor = 1;
    cur = head;

    while (nomor < posisi) {
        if (nomor == posisi - 1) {
            before = cur;
        }

        if (nomor == posisi) {
            del = cur;
        }

        cur = cur->next;
        nomor++;
    }

    before->next = cur;
    delete del;
}

// Change first in single linked list
void changeFirst(string judul, string pengarang, int tB) {
    if (head != NULL) {
        head->judul = judul;
        head->pengarang = pengarang;
        head->tahunTerbit = tB;
    } else {
        cout << "List kosong" << endl;
    }
}

// Change last in single linked list
void changeLast(string judul, string pengarang, int tB) {
    if (tail != NULL) {
        tail->judul = judul;
        tail->pengarang = pengarang;
        tail->tahunTerbit = tB;
    } else {
        cout << "List kosong" << endl;
    }
}

// Change middle in single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (posisi == 1 || posisi == countSingleLinkedList()) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    cur = head;
    int nomor = 1;

    while (nomor < posisi && cur != NULL) {
        cur = cur->next;
        nomor++;
    }

    if (cur != NULL) {
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// Print single linked list
void printSingleLinkedList() {
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
    cur = head;
    while (cur != NULL) {
        cout << "Judul Buku: " << cur->judul << endl;
        cout << "Pengarang Buku: " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku: " << cur->tahunTerbit << endl;

        cur = cur->next;
    }
}
int main (){

    createSingleLinkedList("Kata", "Geez & Aan", 2018);

    printSingleLinkedList();

    cout << "\n\n" << endl;

    addFirst("Dia adalah Kakakku","Tere Liye", 2009);

    printSingleLinkedList();

    cout << "\n\n" << endl;

    addLast("Aroma Karsa","Dee Lestari", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    removeFirst();

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    addLast("11.11","Fiersa Besari", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    removeLast();

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    changeFirst("Berhenti di Kamu","Gia Pratama", 2018);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    addMiddle("Bumi Manusia","Pramoedya Anata Toer", 2005, 2);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    addMiddle("Negeri 5 Menara","Ahmad Fuadi", 2009, 2);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    removeMiddle(5);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;

    changeMiddle("Sang Pemimpi", "Andre Hirata", 2006, 2);

    printSingleLinkedList();
    
    cout << "\n\n" << endl;


    }