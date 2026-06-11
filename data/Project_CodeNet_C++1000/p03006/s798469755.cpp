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
    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    vector<int> x(n), y(n);
    rep (i, n) {
        cin >> x[i] >> y[i];
    }
    map<P, int> cand;
    rep (i, n) {
        rep (j, n) {
            if (i == j) continue;
            int p = x[i] - x[j];
            int q = y[i] - y[j];
            cand[make_pair(p, q)]++;
        }
    }
    int ans = 1e9+7;
    for (auto au: cand) {
        P p = au.first;
        int q = au.second;
        chmin(ans, n - q);
    }
    cout << ans << endl;
}