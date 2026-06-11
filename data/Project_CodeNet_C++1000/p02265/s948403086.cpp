#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

class MyList {
    struct Node {
        int value;
        Node* prev;
        Node* next;
    };

public:
    MyList();
    ~MyList();
    MyList(const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    void Execute(const std::string&, const int);
    void WriteAll() const;

private:
    void Insert(const int);
    void Delete(const int);
    void Delete(Node* node);
    void DeleteFirst();
    void DeleteLast();
    void Clear();

    Node dummy_;
};

MyList::MyList() {
    dummy_.value = 0;
    dummy_.prev = dummy_.next = &dummy_;
}

MyList::~MyList() {
    Clear();
}

void MyList::Execute(const std::string& str, const int x) {
    if (str[0] == 'i') Insert(x);
    else if (str[6] == 'F') DeleteFirst();
    else if (str[6] == 'L') DeleteLast();
    else Delete(x);
}

void MyList::WriteAll() const {
    Node* node = dummy_.next;

    if (node == &dummy_) return;

    while (node != &dummy_) {
        std::cout << node->value;

        node = node->next;
        if (node != &dummy_) std::cout << " ";
    }

    std::cout << std::endl;
}

void MyList::Insert(int x) {
    Node* node = new Node;
    node->value = x;
    node->next = dummy_.next;
    node->prev = &dummy_;

    dummy_.next->prev = node;
    dummy_.next = node;
}


void MyList::Delete(const int x) {
    Node* node = dummy_.next;

    while (node != &dummy_) {
        if (node->value == x) {
            Delete(node);
            break;
        }

        node = node->next;
    }

}

void MyList::Delete(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    delete node;

    prev->next = next;
    next->prev = prev;
}

void MyList::DeleteFirst() {
    Delete(dummy_.next);
}

void MyList::DeleteLast() {
    Delete(dummy_.prev);
}

void MyList::Clear() {
    Node* node = dummy_.next;

    if (node == &dummy_) return;

    while (node != &dummy_) {
        Node* deleteNode = node;
        node = node->next;
        delete deleteNode;
    }

}


int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    MyList li;

    std::string str;
    int x;
    
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        x = 0;
        if (std::cin.peek() != '\n') std::cin >> x;
        li.Execute(str, x);
    }

    li.WriteAll();
    return 0;
}