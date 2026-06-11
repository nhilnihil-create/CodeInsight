#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
typedef pair<int,int> P;

int main(){
    int n,m;
    cin>>n>>m;
    vector<P> dat(m);
    rep(i,m){
        int a,b,n=0;
        cin>>a>>b;
        rep(j,b){
            int c;
            cin>>c;c--;
            n|=(1<<c);
        }
        dat[i]=P(a,n);
    }
    vector<int> dp((1<<n),1e9);
    dp[0]=0;
    rep(i,1<<n){
        rep(j,m){
            int now=(i|dat[j].second);
            int val=dp[i]+dat[j].first;
            dp[now]=min(dp[now],val);
        }
    }
    if(dp[(1<<n)-1]>=1e9) dp[(1<<n)-1]=-1;
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}