#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
int main(){
    int n,t;
    cin>>n>>t;
    vector<pair<int,int>> p(n);
    int amax=0;
    rep(i,n){
        //cin>>a[i]>>b[i];
        cin>>p[i].first>>p[i].second;
        amax = max(amax,p[i].first);
    }
    all(p);
    vector<vector<int>> dp(n+1,vector<int> (t+amax ,-big));
    rep(i,n+1){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){

        rep(j,t+amax){
            if(j-p[i-1].first>=0 &&j-p[i-1].first<t){
                dp[i][j] = max(dp[i-1][j-p[i-1].first]+p[i-1].second,dp[i-1][j]); 
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    /*
    rep(i,n+1){
        rep(j,t+amax+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int ans=0;
    for(int j =0;j<t+amax;j++){
        ans = max(ans,dp[n][j]);
    }
    cout<<ans<<endl;
}