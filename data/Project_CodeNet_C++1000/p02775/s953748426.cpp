#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;
int dp[1000005][2];

int main(){
    string s; cin >> s;
    int sl=s.length();
    dp[0][0]=0;
    dp[0][1]=0;
    rep(i,sl){
        int now=s[sl-i-1]-'0';
    // i桁目はぴったり
        dp[i+1][0]=min(dp[i][0]+now,dp[i][1]+now+1);
    // i桁目は繰り上がり
        if(i==0) dp[i+1][1]=10-now;
        else dp[i+1][1]=min(dp[i][0]+10-now,dp[i][1]+9-now);
    }
  cout << min(dp[sl][0],dp[sl][1]+1) << endl;
return 0;
}