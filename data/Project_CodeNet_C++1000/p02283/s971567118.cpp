#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <class T, class Comp=less<T>>
struct BinarySearchTree {
    struct Node {
        T value;
        Node *parent, *left, *right;
        Node(T v=T()): value(v), parent(NULL), left(NULL), right(NULL) {}
    };
    Node *root;
    Comp comp;
    BinarySearchTree(): root(NULL) {}
    void insert(T key) {
        Node *z=new Node(key);
        Node *x=root;
        while (x != NULL) {
            z->parent = x;
            x = (comp(z->value, x->value)? x->left : x->right);
        }

        if (z->parent == NULL) {
            root = z;
        } else if (comp(z->value, z->parent->value)) {
            z->parent->left = z;
        } else {
            z->parent->right = z;
        }
    }
    template <class Functor>
    void walk_inorder(Functor F, Node *x) {
        if (x == NULL) return;

        walk_inorder(F, x->left);
        F(x);
        walk_inorder(F, x->right);
    }
    template <class Functor>
    void walk_preorder(Functor F, Node *x) {
        if (x == NULL) return;

        F(x);
        walk_preorder(F, x->left);
        walk_preorder(F, x->right);
    }
    template <class Functor>
    void walk_postorder(Functor F, Node *x) {
        if (x == NULL) return;

        walk_postorder(F, x->left);
        walk_postorder(F, x->right);
        F(x);
    }
    ~BinarySearchTree() {
        auto del=[](Node *x) {
            delete x;
        };
        walk_postorder(del, root);
    }
};

int main() {
    size_t m;
    scanf("%zu", &m);

    auto output=[](BinarySearchTree<int>::Node *x)->int {
        return printf(" %d", x->value);
    };

    BinarySearchTree<int> tree;
    for (size_t i=0; i<m; ++i) {
        char buf[1<<3];
        scanf("%s", buf);
        string instr(buf);

        if (instr == "insert") {
            int key;
            scanf("%d", &key);
            tree.insert(key);
        } else if (instr == "print") {
            tree.walk_inorder(output, tree.root);
            printf("\n");
            tree.walk_preorder(output, tree.root);
            printf("\n");
        }
    }

    return 0;
}