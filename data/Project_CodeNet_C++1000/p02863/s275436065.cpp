#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int dp1[3005][3005];

int main(){
    int n,t;
    cin>>n>>t;
    vector<P>p(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        p[i]=P(a,b);
    }
    sort(p.begin(),p.end());
    for(int i=0; i<n; ++i){
        for(int j=0; j<t; ++j){
            if(j-p[i].first>=0)dp1[i+1][j]=max(dp1[i+1][j],dp1[i][j-p[i].first]+p[i].second);
            dp1[i+1][j]=max(dp1[i+1][j],dp1[i][j]);
        }
    }
    int ans=0;
    rep(i,n){
        ans=max(ans,dp1[i][t-1]+p[i].second);
    }
    cout<<ans<<endl;
}