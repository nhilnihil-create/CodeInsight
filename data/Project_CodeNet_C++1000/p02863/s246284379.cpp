#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

int N,T;
vector<pair<int,int>> vec;
int dp[3001][3000];

int main(){
    cin>>N>>T;
    int a,b;
    rep(i,N){
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end());
    rep(j,T) dp[0][j] = 0;
    rep(i,N){
        int a = vec[i].first;
        int b = vec[i].second;
        rep(j,T){
            if(j<a) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j],dp[i][j-a]+b);
        }
    }
    int ans = 0;
    rep(i,N){
        ans = max(ans,dp[i][T-1]+vec[i].second);
    }
    cout<<ans<<endl;
    
    return 0;
}