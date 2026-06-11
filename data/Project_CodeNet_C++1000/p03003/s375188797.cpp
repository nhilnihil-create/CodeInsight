#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
vector<int> S,T;

ll dp[2005][2005];
bool memo[2005][2005];
ll f(int x,int y){
    if(memo[x][y]) return dp[x][y];
  	memo[x][y]=true;
    if(x==0||y==0) dp[x][y]=1;
    else{
        dp[x][y]=(f(x-1,y-1)+(f(x,y-1)-f(x-1,y-1))+(f(x-1,y)-f(x-1,y-1)))%mod;
        if(S[x-1]==T[y-1]) dp[x][y]=(dp[x][y]+f(x-1,y-1))%mod;
    }
    return dp[x][y];
}

int main() {
    int N,M;
    cin>>N>>M;
    S.resize(N);
    T.resize(M);
    for(int i = 0; i < N; i++) cin>>S[i];
    for(int j = 0; j < M; j++) cin>>T[j];
    ll ans = f(N,M);
  	if(ans<0) ans+=mod;
  	cout<<ans<<endl;
}