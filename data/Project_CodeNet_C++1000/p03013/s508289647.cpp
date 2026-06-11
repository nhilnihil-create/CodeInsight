#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

ll dp[110000];

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    rep(i, m-1) {
        if(a[i] + 1 == a[i+1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    dp[0] = 1;
    int no = 0;
    rep(i, n) {
        if(no < m && a[no] == i+1) {
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
            no++;
            i++;
        }
        else {
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
    }
    cout << dp[n] << endl;
}