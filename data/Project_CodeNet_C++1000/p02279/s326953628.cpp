//
//  main.cpp
//  ALDS1_7_A
#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1
#define rep(i,n) for(int i=0;i<(n);++i)
struct Node { int p,l,r;}; // 親　最初の子　右の兄弟
Node T[MAX];
int n,D[MAX];

void print(int u){
    int i,c;
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].p<<", ";
    cout<<"depth = "<<D[u]<<", ";
    if(T[u].p==NIL) cout<<"root, "; // 親がないのが根
    else if(T[u].l==NIL)cout<<"leaf, "; // 子がないのが葉
    else cout<<"internal node, "; // それ以外が内部節点
    cout<<"[";
    
    for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
        if(i)cout<<", "; // 最初以外の節点の出力時
        cout << c;
    }
    cout<<"]"<<endl;
}
void rec(int u,int p){
    D[u]=p; // 深さ　最初は０
    if(T[u].r!=NIL) rec(T[u].r,p); // 兄弟も同じ深さ
    if(T[u].l!=NIL) rec(T[u].l,p+1); // 子の深さには、+1して再帰
    return;
}
int main(int argc, const char * argv[]) {
    int d,v,c;
    int l=0;
    cin>>n; // 節の数（根も含む）　根の節番号は０
    rep(i,n) T[i].p=T[i].l=T[i].r=NIL; // 初期化
    rep(i,n){
        cin>>v>>d; // v:id d:次数（子の数）
        rep(j,d){
            cin>>c; // 子の節番号
            if(j==0) {
                T[v].l=c; // vの最初の子はc
            } else{
                T[l].r=c; // 2番目以降の子は、その前の子の兄弟
            }
            l=c; // ２番目以降の子は、その前の子の兄弟
            T[c].p=v; // 節cの親はv
        }
    }
    int r=0;
    rep(i,n){
        if(T[i].p==NIL) r=i; // 根を探して
    }
    rec(r,0);
    rep(i,n) print(i);
    return 0;
}

