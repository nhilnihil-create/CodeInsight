//
//  main.cpp
//  ALDS1_7_A
//
//  Created by ptyuan on 2018/11/3.
//  Copyright © 2018 YY. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int parent = - 1;
    int left;
    int right;
};

const int kCount = 100000;
const int kNil = -1;
Node tree[kCount];
int D[kCount];
int n = 0;

void depth(int u, int p) {
    D[u] = p;
    if (tree[u].right != kNil) { depth(tree[u].right, p); }
    if (tree[u].left != kNil) { depth(tree[u].left, p + 1); }
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << tree[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    
    if (kNil == tree[u].parent) {
        cout << "root, ";
    } else if (kNil == tree[u].left) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }
    
    cout << "[";
    int c = 0;
    for (int i = 0, c = tree[u].left; c != kNil; c = tree[c].right, i++) {
        if (i > 0) cout << ", ";
        cout << c;
    }
    
    cout << "]" << endl;
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        Node temp;
        temp.parent = temp.left = temp.right = kNil;
        tree[i] = temp;
    }
    int ll = 0;
    for (int i = 0; i < n; ++i) {
        int nodeIndex = kNil;
        scanf("%d", &nodeIndex);
        
        int depth = 0;
        scanf("%d", &depth);
        int parentNode = nodeIndex;
        for (int j = 0; j < depth; j++) {
            int subNodeIndex = kNil;
            scanf("%d", &subNodeIndex);
            
            if (0 == j) {
                tree[parentNode].left = subNodeIndex;
            } else {
                tree[ll].right = subNodeIndex;
            }
            ll = subNodeIndex;
            tree[subNodeIndex].parent = parentNode;
        }
    }
    
    int root = kNil;
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == kNil) {
            root = i;
        }
    }
    
    depth(root, 0);
    
    for (int i = 0; i < n; i++) {
        print(i);
    }
    return 0;
}

