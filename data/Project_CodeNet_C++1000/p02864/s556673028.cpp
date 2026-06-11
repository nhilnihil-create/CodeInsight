#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[n + 5][k + 5] = {};
    memset(dp, 0x3f, sizeof(dp));
    f1(k) {
        dp[0][i] = 0;
    }
    dp[0][0] = 0;
    ll v[n + 5] = {};
    f1 (n) {
        cin >> v[i];
        fr (j, 0, k + 1) {
            fr(z, 1, min(j + 1,i) + 1) {
                dp[i][j] = min(dp[i][j], dp[i-z][j-z+1] + max(0LL,v[i] - v[i-z]));
            }
            //cout << i <<' '<<j<<' '<<dp[i][j] << endl;
        }
    }
    ll mi = 1e18;
    f(n+1) {
        if (i + k >= n) {
            mi = min(mi, dp[i][k-n+i]);
        }
    }
    cout << mi << '\n';
}
