#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
#define DEBUG(x) cout << x << endl;
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;


signed main(){
    string s; cin >> s;
    int n=s.size();
    int dp[n][2];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[0][1]=0;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]) chmax(dp[i][0],dp[i-1][0]+1);
        chmax(dp[i][0],dp[i-1][1]+1);
        if(i==1){
            dp[1][1]=1;
        }
        else{
            chmax(dp[i][1],dp[i-2][0]+1);
            chmax(dp[i][1],dp[i-2][1]+1);
        }
    }
    cout << max(dp[n-1][0],dp[n-1][1]) << endl;
}
