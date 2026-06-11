#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> P(n);
    rep(i,n) cin>>P[i];
    vector<double> sums(n+1);
    sums[0]=0;
    rep(i,n) sums[i+1]=sums[i]+(double)(P[i]+1)/2;
    //rep(i,n+1) cout<<sums[i]<<endl;
    double ans=0;
    rep(i,n-k+1){
        double temp=sums[i+k]-sums[i];
        //cout<<temp<<endl;
        chmax(ans,temp);
    }
    printf("%.15f\n",ans);
    return 0;
}