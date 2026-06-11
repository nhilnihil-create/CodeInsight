#include <bits/stdc++.h>
using namespace std;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;
 
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;
 
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sum(n+1);
    rp(i, 0, n) {
        int a; cin >> a;
        sum[i+1] = (((sum[i] + a -1) % k) + k) % k;
    }
    ll res = 0;
    map<int, ll> m;
    rp(i, 1, n+1) {
        m[sum[i-1]]++;
        if(i-k>=0) m[sum[i-k]]--;
        res += m[sum[i]];
    }
    cout << res << endl;
    // for(auto x: sum) cout << x;
    // cout << endl;
    return 0;
}