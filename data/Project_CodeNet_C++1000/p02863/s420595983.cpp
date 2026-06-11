#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll dp1[3030][3030],dp2[3030][3030];

int main(){
    ll n,t;cin>>n>>t;
    ll a[3030],b[3030];
    rep(i,0,n)cin>>a[i]>>b[i];
    
    rep(i,0,n){
        rep(j,0,t+1){
            dp1[i+1][j]=dp1[i][j];
            if(j-a[i]>=0)dp1[i+1][j]=max(dp1[i+1][j],dp1[i][j-a[i]]+b[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        rep(j,0,t+1){
            dp2[i+1][j]=dp2[i+2][j];
            if(j-a[i]>=0)dp2[i+1][j]=max(dp2[i+1][j],dp2[i+2][j-a[i]]+b[i]);
        }
    }
    /*rep(i,0,n+1){
        rep(j,0,t+1){
            cout<<dp2[i][j]<<" ";
        }
        cout<<endl;
    }*/
    ll an=0;
    rep(i,1,n+1){
        rep(j,0,t){
            an=max(an,dp1[i-1][j]+dp2[i+1][t-1-j]+b[i-1]);
        }
    }
    cout<<an<<endl;
}

    







