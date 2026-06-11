#include<bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (int i=0; i < n; i++)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using LP = pair<ll,ll>;
using P = pair<int,int>;
const ll inf = 1e9;


int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<ll> dp(h+1, inf);
    dp[0] = 0;
    rep(i, h) rep(j, n){
        int idx = min(h, a[j]+i);
        dp[idx] = min(dp[idx], dp[i]+b[j]);
    }
    cout << dp[h] << endl;
}