#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF=1e9;

int main(){
    int h,n;
    cin>>h>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i]>>b[i];
    vector<vector<long long>> dp(n+1,vector<long long>(h+1,INF));
    dp[0][0]=0;

    for(int i=0;i<n;++i){
        for(int j=0;j<=h;++j){
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][min(j+a[i],h)],dp[i+1][j]+b[i]);
        }
    }

    cout<<dp[n][h]<<endl;
}