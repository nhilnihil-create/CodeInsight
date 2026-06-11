#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<double,int> P;

#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 100000000
int main()
{
    int h,n;
    cin >> h >> n;
    vector<int> a(n),b(n);
    vector<vector<int>> dp(n+1,vector<int>(h+1));
    rep(i,n)cin >> a[i] >> b[i];
    rep(i,n+1)dp[i][0]=0;
    rep(i,h+1)dp[0][i]=INF;
    rep(i,n){
        rep(j,h){
            if(a[i]>j+1){
                dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][0]+b[i]);
            }else{
                dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][j+1-a[i]]+b[i]);
            }
        }
    }

    cout << dp[n][h] << endl;

}