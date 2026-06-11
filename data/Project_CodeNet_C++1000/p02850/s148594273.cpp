#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()


int main() {
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    rep (i, n-1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<vector<int>> G(n);
    rep (i, n-1) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    queue<int> Q;
    vector<int> prev(n, -1);
    map<P, int> M;
    prev[0] = 0;
    int k = 1;
    rep (i, G[0].size()) {
        Q.push(G[0][i]);
        M[make_pair(0, G[0][i])] = M[make_pair(G[0][i], 0)] = i + 1;
        prev[G[0][i]] = i + 1;
        k = i + 1;
    }

    while (Q.size()) {
        int f = Q.front();
        Q.pop();
        int ctr = 1;
        for (auto e: G[f]) {
            if (prev[e] != -1) {
                continue;
            }
            if (ctr == prev[f]) {
                ctr++;
            }
            prev[e] = ctr;
            M[make_pair(e, f)] = M[make_pair(f, e)] = ctr;
            Q.push(e);
            chmax(k, ctr);
            ctr++;
        }
    }
    cout << k << endl;
    rep (i, n-1) {
        cout << M[make_pair(a[i], b[i])] << endl;
    }
}