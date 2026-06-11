#include <bits/stdc++.h>
#include <functional>
#define int long long int
using namespace std;
int DP[2001][2001] = {0};
pair<int,int> val[2001];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {cin>>val[i].first;
    val[i].second = i;    }

    sort(val+1,val+(n+1),greater<pair<int,int>>());
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int l = j;
            int r = i-1-j;
            DP[l+1][r] = max(DP[l+1][r], DP[l][r] + abs(val[i].second - l - 1)*val[i].first);
            r = j;
            l = i-1-j;
            DP[l][r+1] = max(DP[l][r+1], DP[l][r] + abs(n - r - val[i].second)*val[i].first); 
        }
    }

    int ans = 0;

    for(int i=0;i<=n;i++)
    ans = max(ans,DP[i][n-i]);

    cout<<ans;

    return 0;
}