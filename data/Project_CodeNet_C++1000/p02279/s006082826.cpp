#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MAX = 1001001;

struct Node {
    int parent, left, right;
};

Node T[MAX];
vector<int> D(MAX, -1);

void setDepth(int u, int p){
    D[u] = p;
    if(T[u].right != -1){
        setDepth(T[u].right, p);
    }
    if(T[u].left != -1){
        setDepth(T[u].left, p+1);
    }
}

void printChildren(int u){
    int c = T[u].left;
    while(c != -1){
        cout << c;
        c = T[c].right;
        if(c != -1){
            cout << ", ";
        }
    }
}

int main() {
    int n; cin >> n;
    int b;

    rep(i,n){
        T[i].parent = T[i].left = T[i].right = -1;
    }

    rep(i,n){
        int id; cin >> id;
        int k; cin >> k;
        rep(j, k){
            int ch; cin >> ch;
            T[ch].parent = id;
            if(j == 0){
                T[id].left = ch;
            } else {
                T[b].right = ch;
            }
            b = ch;
        }
    }

    int r;
    rep(i, n){
        if(T[i].parent == -1){
            r = i;
            break;
        }
    }
    setDepth(r, 0);

    rep(i,n){
        cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i] << ", ";
        if(T[i].parent == -1){
            cout << "root";
        } else if(T[i].left == -1) {
            cout << "leaf";
        } else {
            cout << "internal node";
        }
        cout << ", [";
        printChildren(i);
        cout << "]" << endl;
    }
}
