#include<bits/stdc++.h>
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};

int D[100000];
struct Node T[100000];

void print(int u){
    int i,c;
    printf("node %d: parent = %d, depth = %d, ",u,T[u].parent,D[u]);
    if(T[u].parent == -1)cout << "root, ";
    else if(T[u].left == -1)cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    for(int i = 0, c = T[u].left;c != -1;i++,c = T[c].right){
        if(i)cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void setdepth(int u,int p){
    D[u] = p;
    if(T[u].right != -1){
        setdepth(T[u].right,p);
    }
    if(T[u].left != -1){
        setdepth(T[u].left,p + 1);
    }
}

int main(){
    int n,v,d,c,l,r;
    cin >> n;
    for(int i = 0;i < n;i++){
        T[i].parent = T[i].left = T[i].right = -1;
    }
    for(int i = 0;i < n;i++){
        cin >> v >> d;
        for(int j = 0;j < d;j++){
            cin >> c;
            if(j == 0)T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }
    for(int i = 0;i < n;i++){
        if(T[i].parent == -1)r = i;
    }
    setdepth(r,0);
    for(int i = 0; i < n;i++)print(i);
}
