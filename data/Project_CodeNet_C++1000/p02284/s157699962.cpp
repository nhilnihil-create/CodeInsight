// AOJ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_B
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;
#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

using namespace std;

// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template<class T> void output(std::vector<T> & A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << A[n - 1] << std::endl;
}

struct Node {
    int key;
    Node* parent, *left, *right;
};
Node *nil, *root;

void preParse(Node *node) {
    // if (nbNode == NIL) return;
    cout << " " << node->key;
    if (node->left != nil) preParse(node->left);
    if (node->right != nil) preParse(node->right);
}

void intParse(Node *node) {
    if (node->left != nil) intParse(node->left);
    cout << " " << node->key;
    if (node->right != nil) intParse(node->right);
}
//
//void postParse(int nbNode) {
//    if (node[nbNode].left != NIL) postParse(node[nbNode].left);
//    if (node[nbNode].right != NIL) postParse(node[nbNode].right);
//    cout << " " << nbNode;
//}

void insert(Node* node) {
    Node* tmp = root;
    Node* par = nil;
    while (tmp != nil) {
        par = tmp;
        const int pkey = tmp->key;
        tmp = (node->key < pkey) ? tmp->left : tmp->right;
    }
    // node = tmp;
    if (par == nil) {
        root = node;
    }
    else {
        node->parent = par;
        if (node->key < par->key) {
            par->left = node;
        }
        else {
            par->right = node;
        }
    }
}

Node* find(int key) {
    Node* tmp = root;
    if (tmp == nil) return tmp;
    while (tmp != nil) {
        if (tmp->key == key) return tmp; // found
        if (tmp->key > key) {
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }
    return tmp; // not found: supposed to be tmp
}

void init(Node* node) {
    node->parent = nil;
    node->left = nil;
    node->right = nil;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    nil = new Node;
    init(nil);
    root = nil;

    int n; cin >> n;
    rep(i, n) {
        string order; cin >> order;
        if (order.compare("insert") == 0) {
            int key; cin >> key;
            Node* newNode = new Node;
            init(newNode);
            newNode->key = key;
            if (root == nil) root = newNode;
            else insert(newNode);
        }
        else if (order.compare("find") == 0) {
            int key; cin >> key;
            Node* found = find(key);
            cout << ((found == nil) ? "no" : "yes") << endl;
        }
        else {
            intParse(root); cout << endl;
            preParse(root); cout << endl;
        }
    }

    return 0;
}

