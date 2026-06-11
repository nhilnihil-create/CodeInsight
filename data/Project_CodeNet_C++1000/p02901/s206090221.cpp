#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


static const long long INF=1LL<<60;

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> c(m,0);
    vector<long long> a(m);
    for(int i=0;i<m;++i){
        int t;
        cin>>a[i]>>t;
        for(int j=0;j<t;++j){
            int bit;
            cin>>bit;
            --bit;
            c[i]+=(1<<bit);
        }
    }

    vector<vector<long long>> dp(m+1,vector<long long>(1<<15,INF));
    dp[0][0]=0;

    for(int i=0;i<m;++i){
        for(int j=0;j<(1<<n);++j){
            chmin(dp[i+1][j],dp[i][j]);
            int nj=j|c[i];
            chmin(dp[i+1][nj],dp[i][j]+a[i]);
        }
    }

    cout<<(dp[m][(1<<n)-1]<INF?dp[m][(1<<n)-1]:-1)<<endl;
}