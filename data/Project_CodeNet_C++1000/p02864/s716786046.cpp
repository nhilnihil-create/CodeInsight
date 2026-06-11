//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<vector<vector<int> > > vvvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vll h(n+1);
    h[0]=0;
    REP(i,n) cin >> h[i+1];
    vvll dp(n+1, vll(n+1,LLINF));
    dp[0][0] = 0LL;
    //dp[1][0]=0;
    dp[1][1] = h[1];
    for(int i=2;i<=n;++i){
        //dp[i][0] = 0;
        dp[i][1]=h[i];
        for(int j=2;j<=i;++j){
            for(int l=1;l<i;++l){
                dp[i][j] = min(dp[i][j], dp[l][j-1]+max(0LL,h[i]-h[l]));
            }
        }
    }
    ll ans = LLINF;
    /* 
    REP(i,n){
        REP(j,n){
            if(dp[i+1][j+1]==LLINF){
                cout << -1 << " ";
            }else{
                cout << dp[i+1][j+1] << " ";
            }
            
        }
        cout << endl;
    }
    */
    REP(i,n+1){
        ans = min(ans, dp[i][n-k]);
    }
    cout << ans << endl;
    return 0;
}