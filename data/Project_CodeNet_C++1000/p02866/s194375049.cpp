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
    vector<ll> d(n);
    rep (i, n) {
        cin >> d[i];
    }
    vector<ll> e(100002, 0);
    rep(i, n) {
        e[d[i]]++;
    }
    if (d[0] != 0 || e[0] > 1) {
        cout << 0 << endl;
        exit(0);
    }
    ll ans = 1;
    ll mod = 998244353;
    bool flag = false;
    rep(i, 1, 100002) {
        if (flag) {
            if (e[i] > 0) {
                cout << 0 << endl;
                exit(0);
            }
        }
        else {
            if (e[i] == 0) {
                flag = true;
            }
            else {
                rep(j, e[i]) {
                    ans *= e[i-1];
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << endl;
}
