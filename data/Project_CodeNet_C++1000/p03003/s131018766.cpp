#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int MOD = 1000000007, MAX = 2000000007, MAXN = 2005;
ll s[MAXN], t[MAXN],sum[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>s[i];
    for(int i=0; i<m; i++)
        cin>>t[i];   
    for(int i=0; i<=n; i++)
        sum[i][0] = 0;
    for(int i=0; i<=m; i++)
        sum[0][i] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j] = (sum[i-1][j] + sum[i][j-1] + MOD - sum[i-1][j-1])%MOD;
            if(s[i-1] == t[j-1])
            {
                sum[i][j] += (sum[i-1][j-1] + 1)%MOD;
            }
            sum[i][j]%=MOD;
        }
    }
    cout<<(sum[n][m]+1)%MOD;
	return 0;
}
