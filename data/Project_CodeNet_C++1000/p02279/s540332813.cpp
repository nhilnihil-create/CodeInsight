#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0; i<(n); i++)
#define REP2(i,x,n) for(ll i=x; i<(n); i++)
#define REP3(i,x,n) for(ll i=x; i>(n); i--)
#define ALL(n) begin(n),end(n)
#define MAX 500000
#define SENTINEL 2000000000
#define NIL -1
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
//ノードの数の変化がないのでleft-child,right-sibling representationによって木を表す

struct Node{ll parent,left,right;};
struct Node T[MAX];
ll D[MAX],N;


//あるノードの親があるか(NILはnotNode)でふかさを測る
ll getDepth(ll u){
    ll d = 0;
    while(T[u].parent!=NIL){
        u = T[u].parent;
        d++;
        }
    return d;
}
//下の方が高速
//u:ノード番号　D:各ノードの深さ 右の兄弟の深さと、最左のこの深さを探索　
void setDepth(ll u,ll p){
    D[u] = p;
    if(T[u].right != NIL){
        setDepth(T[u].right,p);
    }
    if(T[u].left != NIL){
        setDepth(T[u].left,p+1);
    }
}

void printChildren(ll u){
    ll i,c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].parent == NIL)cout << "root, ";
    else if(T[u].left == NIL)cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    for(ll i = 0,c = T[u].left;c != NIL;i++,c = T[c].right){
        if(i)cout <<", ";
        cout << c;
    }
    cout << "]" << endl;
    // ll c = T[u].left;
    // while(c != NIL){
    //     cout << c;
    //     c = T[c].right;
    // }
}


int main(){
    ll i,j,d,v,c,left,right;
    cin >> N;
    //初期化
    REP(i,N){
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    REP(i,N){
        cin >> v >> d;
        REP(j,d){
            cin >> c;
            if(j==0)T[v].left = c;
            else T[left].right = c;
            left = c;
            T[c].parent =v;
        }
    }
    REP(i,N){
        if(T[i].parent == NIL)right = i;
    }
    setDepth(right,0);
    REP(i,N)printChildren(i);
    return 0;
}
