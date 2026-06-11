#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

ll dp[3007][3007];
int main(){
    ll n,t;
    cin>>n>>t;
    vector<lP>food(n);
    rep(i,n){
        cin>>food[i].second>>food[i].first;
    }
    sort(food.begin(),food.end());
    dp[0][0]=0;
    rep(i,n)rep(j,t){
        if(i==0){        
            dp[i][j]=0;
        }
        if(j<food[i].second){
            dp[i+1][j]=dp[i][j];
            
        }
        else dp[i+1][j]=max(dp[i][j],dp[i][j-food[i].second]+food[i].first);
    }
    int index=n,tt=t-1;

    while(index>0){
        if(dp[index][tt]==dp[index-1][tt])break;
        tt-=food[index-1].second;
        index--;
    }
    ll ans=dp[n][t-1];
    //cout<<ans<<endl;
    if(index!=0)ans+=food[index-1].first;
    ans=max(ans,dp[n-1][t-1]+food[n-1].first);
    cout<<ans<<endl;
    return 0;
}