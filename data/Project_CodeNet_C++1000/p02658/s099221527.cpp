#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = 3e18;
const int inf = (1<<29);

int main() {

    int n;
    cin >> n;
    vector<ll> a(n);
    bool zero = 0;
    REP(i, n) {
        cin >> a[i];
        if (a[i] == 0) zero = 1;
    }

    if (zero) {
        cout << 0 << endl;
        return 0;
    }
    
    ll res = 1;
    for(int i = 0; i < n; i++) {
        if (res > INF/a[i]) {
            cout << -1 << endl;
            return 0;
        } else {
            res *= a[i];
        }
        
    }

    if(res > ll(1e18)) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}