#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;
const int MOD=1000000007;

int main()
{
    speed;
    cout << fixed << setprecision(9);
    /*start*/
    int n, m;
    cin>>n>>m;
    map<int, bool>a;
    rep(i, m) {
        int b;
        cin>>b;
        a[b]=true;
    }
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=a[1]?0:1;
    ffor(i, 2, n+1) {
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
        if (a[i])dp[i]=0;
    }
    c(dp[n]);
}
