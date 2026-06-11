//
// Created by ?????°?????? on 2016/04/05.
//

#include <iostream>
using namespace std;
const int MAX = 100000;
const int NIL = -1;

struct Node{
    // ????????????????§????
    int parent;
    int left_child;
    int right_sibling;
};

Node T[MAX];
int n,D[MAX];

void print(int u){
    int i,c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    
    if(T[u].parent == NIL) cout << "root, ";
    else if (T[u].left_child == NIL) cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    for (int i = 0 , c = T[u].left_child; c != NIL ; ++i, c = T[c].right_sibling) {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int getDepth(int u){
    int d = 0;
    while(T[u].parent != NIL){
        u =T[u].parent;
        d++;
    }
    return d;
}

int main (){
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        T[i].left_child = T[i].right_sibling = T[i].parent = NIL;
    }

    int num,degree,child,left_child,right_sibling,depth;
    for (int i = 0; i < n ; ++i) {
        cin >> num >> degree;
        for (int j = 0; j < degree ; ++j) {
            cin >> child;
            if(j == 0) T[num].left_child = child;
            else T[left_child].right_sibling = child;
            left_child = child;
            T[child].parent = num;
        }
    }
    for (int i = 0; i < n ; ++i) {
        if (T[i].parent == NIL) right_sibling = i;
    }
    for (int i = 0; i < n ; ++i) {
    D[i] = getDepth(i);        
    }

    for (int i = 0; i < n ; ++i) {
        print(i);
    }
    return 0;
}