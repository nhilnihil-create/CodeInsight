#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll dp[1005][10005];

int main() {
    ll H,N;
    cin>>H>>N;
    vector<vector<ll>> v(N,vector<ll>(2));
    rep(i,N) cin>>v[i][0]>>v[i][1];
    rep(i,10005){
        dp[0][i]=((i-1)/v[0][0]+1)*v[0][1];
    }
  	rep(i,1005) dp[i][0] = 0;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= H; j++){
            if(j>v[i][0]) dp[i][j]=min(dp[i-1][j],dp[i][j-v[i][0]]+v[i][1]);
            else dp[i][j] = min(dp[i-1][j],v[i][1]);
        }
    }
    cout<<dp[N-1][H]<<endl;
}