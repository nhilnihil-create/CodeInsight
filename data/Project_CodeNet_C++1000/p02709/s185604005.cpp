#include<bits/stdc++.h>
#define int long long
#define inf 10000000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n;

pair<int, int>a[2001];
vector <vector <int> > dp(2001, vector <int>(2001, -inf));

signed main()
{
     FLASH

    cin>>n;
    for(int i = 1; i <= n; i++) {cin>>a[i].first; a[i].second = i;}

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    dp[0][0] = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            int l = j,  r = n - (i - j) + 1;
            if(j != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] +  a[i].first*abs(a[i].second - l));
            dp[i][j] = max(dp[i][j],  dp[i - 1][j] + a[i].first*abs(a[i].second - r));
            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i = 0; i <= n; i++) ans = max(ans, dp[n][i]);
    cout<<ans<<'\n';
}