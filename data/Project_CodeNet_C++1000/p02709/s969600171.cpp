#include <bits/stdc++.h>
#define ll long long
#define pp push_back
#define fr first
#define sc second

using namespace std;

ll n;
pair<ll,ll>a[2002];
ll dp[2002][2020];
ll solve(int i,int j){
    if(i > n)return 0;
    ll &ret = dp[i][j];
    if(ret + 1)return ret;
    ret = 0;
    ll v = a[i].fr;
    ll d1 = abs(a[i].sc - j);
    ll d2 = abs(a[i].sc - (n - (i - j)));
    ret = max(ret , solve(i + 1 , j) + d2 * v);
    ret = max(ret , solve(i + 1 , j + 1) + d1 * v);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i].fr , a[i].sc = i;
    sort(a + 1 , a + n + 1);
    reverse(a + 1 , a + n + 1);
    cout << solve(1,1) << '\n';
    return 0;
}
