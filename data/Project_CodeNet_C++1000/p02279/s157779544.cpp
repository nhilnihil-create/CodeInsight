#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<int,int> P;

#define MAX 100005
#define NIL -1
// 左子右兄弟表現
struct Node{
    int p,l,r;
};

Node T[MAX];
int D[MAX];

int getDepth(int u){
    int d = 0;
    while(T[u].p!=NIL){
        ++d;
        u = T[u].p;
    }
    return d;
}

// あるnodeの性質を書く
void setDepth(int u, int d){
    D[u]=d;
    // uの子がいる
    if(T[u].l!=NIL){
        setDepth(T[u].l,d+1);
    }
    // uの兄弟がいる
    if(T[u].r!=NIL){
        setDepth(T[u].r,d);
    }    
}

void printChildren(int u){
    vector<int> rel;
    if(T[u].l!=NIL){
        int x = T[u].l;
        while(x!=NIL){
            rel.push_back(x);
            x=T[x].r;
        }
    }
    cout << "node " << u<<":";
    cout << " parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";
    if(T[u].p==NIL){
        cout << "root,";
    }else if(T[u].l==NIL)cout << "leaf,";
    else{
        cout << "internal node,";
    }
    cout << " [";
    rep(i,rel.size()){
        if(rel.size()>1){
            if(i==0){
                cout<<rel[i];
            }else cout << ", "<<rel[i];
        }else{
            cout << rel[i];
        }
        
    }
    cout << "]"<<endl;;
    return;
}

int main(){
    int n,d,v,c,l,r;
    cin >> n;
    // 配列の初期化
    rep(i,n)T[i].l=T[i].r=T[i].p=NIL;

    rep(i,n){
        cin >> v >> d;
        // d個の子ができる
        rep(j,d){
            cin >> c;
            // vの子の一番目の場合
            if(j==0){
                T[v].l = c;
            }//二番目以降の場合
            else{
                T[l].r=c;
            }
            l=c;
            T[c].p = v;
        }
    }
    // 0番目が必ずしも根ではないので、根を探す
    int parent;
    rep(i,n){
        if(T[i].p==NIL)parent=i;
    }
    setDepth(parent,0);
    rep(i,n)printChildren(i);
    return 0;
}
