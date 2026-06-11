#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#define ull unsigned long long
#define int long long
#define ll long long
#define fr(i, n) for (int i = 0; i < n; i++)
#define frf(i, j, n) for (int i = j; i <= n; i++)
#define frd(i, n) for (int i = n; i >= 0; i--)
#define mp(i, j) make_pair(i, j)
#define pb(x) push_back(x)
using namespace std;
// const int MAX = 1e6 + 1;
// typedef vector<vector<ll>> matrix;
 const ll PRIME = 1e9 + 7;
// typedef pair<int,pair<int,int> >  ppi;
// const ll MAX = 1e6 + 1;


void solve()
{
   int s;
   cin>>s;
   int dp[s+1];
       memset(dp,0,sizeof(dp));

    dp[0]=1;
    frf(i,3,s)
    {
        frf(j,3,i)
        {
            if(i-j>=0)
            dp[i]+=dp[i-j];
            dp[i]%=PRIME;
        }
    }
  cout<<dp[s];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    // int k = 1;
    // cin >> t;
    t = 1;
    while (t--)
    {
        // cout << "Case #" << k++ << ": ";
        solve();
    }
}
