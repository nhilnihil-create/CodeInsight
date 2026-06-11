#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const ll mod = 1e9 + 7;

int main(){
    int n, k;
    cin >> n >> k;

    ll res = 0;
    for (ll i = k; i <= n + 1; ++i) {
        res += i * (n - i + 1) + 1;
        res %= mod;
    }
    cout << res << endl;
}