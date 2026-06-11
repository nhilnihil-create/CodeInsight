#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[310][310][310];

int main(){
    int N,K; cin >> N >> K;
    vector<int> H(N);
    rep(i,N) cin >> H[i];
    rep(i,310)rep(j,310)rep(k,310) dp[i][j][k] = LINF;
    dp[0][0][0] = 0;
    rep(i,N)rep(j,K+1)rep(k,j+1){
        if(i-k >= 0) dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][k]+max(0,(i-k == -1?H[i]:H[i]-H[i-k-1])));
        dp[i+1][j+1][k+1] = min(dp[i+1][j+1][k+1],dp[i][j][k]);
    }
    ll ans = LINF;
    rep(i,K+1)rep(j,i+1){
        ans = min(ans,dp[N][i][j]);
    }
    cout << ans << endl;
}
