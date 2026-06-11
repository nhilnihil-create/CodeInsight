
// Problem : A - Range Flip Find Route
// Contest : AtCoder - AtCoder Grand Contest 043
// URL : https://atcoder.jp/contests/agc043/tasks/agc043_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n,m,a[101][101];

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][j] = c=='.'?0:1;
        }
    }
    int dp[n+1][m+1];
    dp[1][1] = a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1) continue;
            if(i==1) dp[i][j] = dp[i][j-1] + (a[i][j-1]?0:a[i][j]);
            else if(j==1) dp[i][j] = dp[i-1][j] + (a[i-1][j]?0:a[i][j]);
            else dp[i][j] = min(dp[i-1][j] + (a[i-1][j]?0:a[i][j]) ,dp[i][j-1] + (a[i][j-1]?0:a[i][j]));
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
