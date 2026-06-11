#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = int(1e10);
//const ll inf = ll(1e19);
const int mod = int(1e9) + 7;

int h, n, ab[1001][2];
int dp[10001];
int main(){
    cin >> h >> n;
    rep(i, n){
        int a, b; cin >> a >> b;
        ab[i][0] = a;
        ab[i][1] = b;
    }
    rep(i, 10001) dp[i] = inf;
    dp[0] = 0;
    rep(i, h){
        if(dp[i] == inf) continue;
        rep(j, n){
            if(i + ab[j][0] <= h)
            dp[i + ab[j][0]] = min(dp[i + ab[j][0]], dp[i] + ab[j][1]);
            else
            dp[h] = min(dp[h], dp[i] + ab[j][1]);
        }
    }
    cout << dp[h] << endl;
}