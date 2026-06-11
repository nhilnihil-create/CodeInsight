#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n;
    cin>>n;
    int dp[10][10]={0};
    rep(i,1,n+1){
        if(i%10==0)continue;
        string s=to_string(i);
        dp[s.at(0)-'0'][i%10]++;
    }
    int ans=0;
    rep(i,1,10){
        rep(j,1,10){
            ans+=dp[i][j]*dp[j][i];
        }
    }
    cout<<ans<<endl;
return 0;
}