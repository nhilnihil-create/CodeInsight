#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    ll s; cin >> s;
    ll x2 = 1000000000;
    ll b = ceil((long double)s / (long double)x2);
    ll a = (x2 - s%x2)%x2;
    ll ans[] = {0, 0, x2, 1, a, b};
    rep(i, 6){
        cout << ans[i] << " ";
    }
    cout << endl;
}
