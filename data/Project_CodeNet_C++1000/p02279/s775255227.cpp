// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;
const int NIL = -1;

struct Node{
    int p, l, r;
};

vector<Node> T(100010, {NIL, NIL, NIL});
vector<int> D(100010);

void setDepth(int u, int p){
    D[u] = p;
    if(T[u].l != NIL) setDepth(T[u].l, p + 1);
    if(T[u].r != NIL) setDepth(T[u].r, p);
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].p == NIL) cout << "root, ";
    else if(T[u].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for(int c = T[u].l, j = 0; c != NIL; c = T[c].r, j++){
        if(j) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int N;
    cin >> N;
    rep(i, N){
        int id, k;
        cin >> id >> k;
        int c1, c2;
        rep(j, k){
            cin >> c1;
            if(j == 0){
                T[id].l = c1;
                T[c1].p = id;
                c2 = c1;
            } else {
                T[c2].r = c1;
                T[c1].p = id;
                c2 = c1;
            }
        }
    }

    int root;
    rep(i, N){
        if(T[i].p == NIL){
            root = i;
            break;
        }
    }
    
    setDepth(root, 0);

    rep(i, N) print(i);
}
