#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define NIL -1

struct Node{int parent, left, right;};
vector<Node> T(MAX);
vector<int> D(MAX);


int getDepth(int u){
    int d = 0;
    while(T.at(u).parent != NIL){
        u = T.at(u).parent;
        d++;
    }
    return d;
}

void setDepth(int u, int p){
    D.at(u) = p;
    if(T.at(u).right != NIL) setDepth(T.at(u).right, p);
    if(T.at(u).left != NIL)  setDepth(T.at(u).left, p + 1);
}

void printChildren(int u){
    int c = T.at(u).left;
    while(c != NIL){
        cout << c;
        c = T.at(c).right;
    }
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T.at(u).parent << ", ";
    cout << "depth = " << D.at(u) << ", ";

    if(T.at(u).parent == NIL) cout << "root, ";
    else if(T.at(u).left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for(int i = 0, c = T.at(u).left; c != NIL; i++, c = T.at(c).right){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int n,v,d,c,l,r;
    cin >> n;
    for(int i = 0;i<n;i++) T.at(i).parent = T.at(i).left = T.at(i).right = NIL;

    for(int i = 0;i<n;i++){
        cin >> v >> d;
        for(int j = 0;j<d;j++){
            cin >> c;
            if(j == 0) T.at(v).left = c;
            else T.at(l).right = c;
            l = c;
            T.at(c).parent = v;
        }
    }
    for(int i = 0;i<n;i++){
        if(T.at(i).parent == NIL) r = i; 
    }

    setDepth(r,0);
    for(int i = 0;i<n;i++) print(i);

    return 0;
}


