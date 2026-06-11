#include <bits/stdc++.h> //全てのヘッダファイルをインクルード

//ループ
#define rep(i, n) for(int i = 0; i < n; i++) //普通のループ
#define repr(i, n) for(int i = n; i >= 0; i--) //逆ループ

//型名省略
typedef long long ll;
//値
static const ll MX = 100005;
static const ll MX_ll = 1e18;

using namespace std;

//#include "./lib/generic/search.h"

//木
struct Node{
    int p, l, r;
};
Node T[100005];
int n, D[100005];

void print(int u){
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].p == -1) cout << "root, ";
    else if(T[u].l == -1) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(i=0, c=T[u].l; c!=-1; i++, c=T[c].r){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
 }

int rec(int u, int p){
    D[u] = p;
    if(T[u].r != -1) rec(T[u].r, p);
    if(T[u].l != -1) rec(T[u].l, p+1);
}

int main(){
    int i, j, d, v, c, l, r;
    cin >> n; //接点の個数
    rep(i, n) T[i].p=T[i].l=T[i].r = -1;

    rep(i, n){
        cin >> v >> d;
        rep(j ,d){
            cin >> c;
            if(j==0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }

    rep(i, n){
        if(T[i].p == -1) r = i;
    }

    rec(r, 0);

    rep(i, n) print(i);

}
