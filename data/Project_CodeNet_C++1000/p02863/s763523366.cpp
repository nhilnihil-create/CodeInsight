#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,t;cin >> n >> t;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    int dp[n+1][t][2]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            chmax(dp[i+1][j][0],dp[i][j][0]);
            chmax(dp[i+1][j][1],dp[i][j][1]);
            if(j+a[i]<t){
                chmax(dp[i+1][j+a[i]][0],dp[i][j][0]+b[i]);
                chmax(dp[i+1][j+a[i]][1],dp[i][j][1]+b[i]);
            }
            chmax(dp[i+1][j][1],dp[i][j][0]+b[i]);
        }
    }
    int ans=0;
    for(int i=0;i<t;i++){
        chmax(ans,max(dp[n][i][0],dp[n][i][1]));
    }
    cout << ans << endl;
}