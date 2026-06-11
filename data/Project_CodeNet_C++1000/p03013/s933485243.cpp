#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#include<bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
const long long INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;
const ll MOD=1000000007;

int main(){
    int n, m; cin >> n >> m;
    ll dp[100100];
    rep(i, 100101) dp[i]=0;
    rep(i, m){
        ll b; cin >> b;
        dp[b]=-1;
    }

    dp[0]=1;

    reps(i, 0, n+1){
        if(dp[i]==-1){
            continue;
        }
        if(dp[i+1]!=-1){
            dp[i+1]+=dp[i];
            dp[i+1]%=MOD;
        }
        if(dp[i+2]!=-1){
            dp[i+2]+=dp[i];
            dp[i+2]%=MOD;
        }
    }
    out(dp[n]);
}