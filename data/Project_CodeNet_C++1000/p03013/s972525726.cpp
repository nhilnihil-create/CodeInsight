#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



signed main(){
    int N, M;
    cin >> N >> M;
    set<int> a;
    rep(i, M){
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }

    vi dp(N+10);
    dp[0] = 1;
    if(!a.count(1)) dp[1] = 1;

    for(int i = 2; i <= N; i++){
        if(!a.count(i-1)) dp[i] += dp[i-1];
        if(!a.count(i-2)) dp[i] += dp[i-2];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

}