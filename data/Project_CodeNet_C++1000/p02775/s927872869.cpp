#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) << num << endl;
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    string s; cin >> s;
    int n=s.size();
    int dp[n+1][2];
    dp[0][0]=0;
    dp[0][1]=1;
    rep(i,n){
        int x=s[i]-'0';
        dp[i+1][0]=min(dp[i][0]+x,dp[i][1]+10-x);
        dp[i+1][1]=min(dp[i][0]+x+1,dp[i][1]+9-x);
    }
    cout << dp[n][0] << endl;
}


