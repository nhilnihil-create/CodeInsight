#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    int n;
    cin >> n;
    vector<ll> vi(n);
    REP(i, n)
    cin >> vi[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    set<int> si;
    REP(i, n)
    {
        int idx=-1;
        ll maxa=0;
        REP(j, n)
        {
            if(si.find(j)==si.end()&&vi[j]>maxa){
                idx=j;
                maxa=vi[j];
            }
        }
        si.insert(idx);
        for(int j=0;j<=i;j++){
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+abs(idx-j)*vi[idx]);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+((n-1)-idx-(i-j))*vi[idx]);
        }
    }
    ll ans=0;
    REP(i,n+1)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
}