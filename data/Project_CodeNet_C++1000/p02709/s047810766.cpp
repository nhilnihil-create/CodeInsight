#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define reps(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) for(int i=0;i<int(b);i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
#define M 998244353
#define N 1000000007
ll dp[2005][2005] = {};
int main()
{
    csl;
    ll n;
    cin >> n;
    pll a[n+1];
    reps(i,1,n+1)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a+1,a+n+1,greater<pll>());
    reps(i,1,n+1)
    {
        reps(j,0,i)
        {
            ll L = j;
            ll R = i-1-j;
            dp[L+1][R] = max(dp[L+1][R],dp[L][R] + abs(L+1-a[i].second)*a[i].first);

              R = j;
              L = i-1-j;
              dp[L][R+1] = max(dp[L][R+1],dp[L][R] + abs(n - R - a[i].second)*a[i].first);
        }
    }

    ll cnt = 0;
    rep(i,n+1)
    {
        cnt = max(cnt,dp[i][n-i]);
    }

    cout << cnt << endl;

}
