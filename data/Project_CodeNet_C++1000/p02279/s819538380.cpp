#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define MAX 100010

struct Node{
    int parent, left, right;
};
Node T[MAX];
int Depth[MAX];

void rec(int u, int p){//深さを求める関数
    Depth[u] = p;
    if(T[u].right != NIL) rec(T[u].right, p);//右の兄弟には同じ深さを
    if(T[u].left != NIL) rec(T[u].left, p + 1);//最も左(子)には自身の深さ+1を
}

void print(int u){
    printf("node %d: parent = %d, depth = %d, ", u, T[u].parent, Depth[u]);
    if(T[u].parent == NIL) printf("root, [");
    else if(T[u].left == NIL) printf("leaf, [");
    else printf("internal node, [");
    for(int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){
        if(i) cout << ", ";
        printf("%d", c);
    }
    cout << "]" << endl;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for(int i = 0; i < n; i++){
        int v, d, c, l;
        cin >> v >> d;
        for(int j = 0; j < d; j++){
            cin >> c;
            if(j == 0) T[v].left = c;//最も左は子
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }

    int r;
    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL) r = i;
    }
    rec(r, 0);
    for(int i = 0; i < n; i++) print(i);
    return 0;
}


