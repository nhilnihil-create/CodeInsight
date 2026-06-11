#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
int a[maxn];
ll dp[maxn][2];
ll dfs(int now, int lim) {
    if (now == -1) {
        return 1;
    }
    if (~dp[now][lim]) {
        return dp[now][lim];
    }
    int ub = lim ? a[now] : 1;
    ll sum = 0;
    if (ub == 0) {
        sum = dfs(now - 1, 1);
    }
    else {
        if (lim) {
            sum = 2 * dfs(now-1,1) + dfs(now-1,0);
        }
        else {
            sum = 3 * dfs(now-1,0);
        }
    }
    sum %= mod;
    return dp[now][lim] = sum;
}
ll solve(string s) {
    memset(dp, -1, sizeof(dp));
    int ptr = 0;
    while(s.size()) {
        a[ptr++] = s.back() - '0';
        s.pop_back();
    }
    return dfs(ptr-1,1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << solve(s) << '\n';
}