#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,n;
    cin>>h>>n;
    int a,b;
    p p[n];
    rep(i,n){
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }
    vector<int>dp(10005,1e9);
    dp[h]=0;
    for(int i=h;i>=0;i--){
        rep(j,n){
            dp[max(0,i-p[j].first)]=min(dp[max(0,i-p[j].first)],dp[i]+p[j].second);
        }
    }
        cout<<dp[0]<<endl;

    return 0;
}
