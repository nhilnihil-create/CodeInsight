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

ll dp[2010][2010];

int main(){
    int N,M; cin >> N >> M;
    vector<int> S(N),T(M);
    rep(i,N) cin >> S[i];
    rep(i,M) cin >> T[i];

    rep(i,N+1) dp[i][0] = 1;
    rep(i,M+1) dp[0][i] = 1;
    rep(i,N)rep(j,M){
        if(S[i] == T[j]){
            dp[i+1][j+1] += dp[i+1][j]+dp[i][j+1];
            dp[i+1][j+1] %= MOD;
        }
        else{
            dp[i+1][j+1] += ((dp[i][j+1]+dp[i+1][j])%MOD-dp[i][j]+MOD)%MOD;
            dp[i+1][j+1] %= MOD;
        }
    }
    cout << dp[N][M] << endl;

}

