#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 25;

struct node{
    int id = -1;
    int parent = -1;
    int degree = 0;
    int left = -1;
    int right = -1;
    int sibling = -1;
};

node nodes[MAX];

int getDegree(int left, int right) {
    if (left < 0 && right < 0) {
        return 0;
    }
    
    if (left > -1 && right > -1) {
        return 2;
    }
    
    return 1;
}

void preorder(int id) {
    if (id < 0) { return; }
    printf(" %d", id);
    preorder(nodes[id].left);
    preorder(nodes[id].right);
}

void inorder(int id) {
    if (id < 0) { return; }
    inorder(nodes[id].left);
    printf(" %d", id);
    inorder(nodes[id].right);
}

void postorder(int id) {
    if (id < 0) { return; }
    postorder(nodes[id].left);
    postorder(nodes[id].right);
    printf(" %d", id);
}

int main() {
    int N;

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int id, left, right;
        scanf("%d", &id);
        scanf("%d", &left);
        scanf("%d", &right);
        nodes[id].id = id;
        nodes[id].left = left;
        nodes[id].right = right;
        nodes[id].degree = getDegree(left, right);
        
        if (left != -1) {
            nodes[left].parent = id;
            nodes[left].id = left;
            nodes[left].sibling = right;   
        }
        
        if (right != -1) {
            nodes[right].parent = id;
            nodes[right].id = right;
            nodes[right].sibling = left;   
        }
    }
    
    int root = 0;
    for (int i = 0; i < N; i++) {
        if (nodes[i].parent == -1) { root = nodes[i].id; break; }
    }
    
    cout << "Preorder" << endl;
    preorder(root);
    cout << endl;
    
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;
    
    return 0;
}
