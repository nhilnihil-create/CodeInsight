#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
char s[101][101];
int dp[101][101];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>s[i][j];
    repn(i,H) fill(dp[i]+1,dp[i]+W+1,INF);

    dp[1][1]=0;
    repn(i,H){
        repn(j,W){
            if(i<H){
                int cnt=dp[i][j];
                if(s[i][j]!=s[i+1][j]) cnt++;
                dp[i+1][j]=min(dp[i+1][j],cnt);
            }
            if(j<W){
                int cnt=dp[i][j];
                if(s[i][j]!=s[i][j+1]) cnt++;
                dp[i][j+1]=min(dp[i][j+1],cnt);
            }
        }
    }
    int ans=dp[H][W]/2;
    if(s[1][1]=='#' || s[H][W]=='#') ans++;

    cout<<ans<<endl;
}