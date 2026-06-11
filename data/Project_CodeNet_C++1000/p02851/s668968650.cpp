#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + a[i];
    }
    map<ll, ll> mp;
    for (int i = 0; i <= min(n, k-1); ++i) {
        mp[(sum[i] - i) % k]++;
    }

    ll res = 0;
    for (int i = 0; i <= n; ++i) {
        mp[(sum[i] - i) % k]--;
        res += mp[(sum[i] - i) % k];
        if (i+k > n) continue;
        mp[(sum[i+k] - (i+k)) % k]++;
    }
    cout << res << endl;
}