#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(10, vector<int>(10, 0));
    int keta = 1;
    rng(i, 1, n+1) {
        int r = i%10;
        int l = i/keta;
        if (l == 10) {
            keta *= 10;
            l = 1;
        } 
        if (r==0) continue;
        dp[l][r]++;
    }
    ll ans = 0;
    rng(l, 1, 10) {
        rng(r, 1, 10) {
            ans += dp[l][r] * dp[r][l];
        }
    }
    cout << ans << endl;
    return 0;
}