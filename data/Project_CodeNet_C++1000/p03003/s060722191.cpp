#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;
int dp[2005][2005];
int v1[2005] ,v2[2005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    f1(n) {
        cin >> v1[i];
    }
    f1(m) {
        cin >> v2[i];
    }
    f(n + 1) {
        dp[i][0] = 1;
    }
    f(m + 1) {
        dp[0][i] = 1;
    }
    f1(n) {
        fr(j,1,m+1) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if (v1[i] == v2[j]) {
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] %= mod;
            dp[i][j] += mod;
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][m] << endl;
}