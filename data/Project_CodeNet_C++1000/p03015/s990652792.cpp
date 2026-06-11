#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vecctor<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

constexpr ll mod = 1e9+7;

int main(){
    string L;
    cin >> L;
    ll N = L.size();
    VVL dp(N+10, VL(2, -1));
    dp[1][0] = 2; dp[1][1] = 1;
    rep(d, 1, N){
        // smaller -> smaller
        dp[d+1][1] = 3*dp[d][1];
        dp[d+1][1] %= mod;
        // exact -> smaller (L_i = 1 and a_i = 0 and b_i = 0)
        if(L[d] == '1'){
            dp[d+1][1] += dp[d][0];
            dp[d+1][1] %= mod;
        }
        // exact -> exact L_i = a_i XOR b_i
        if(L[d] == '1'){
            dp[d+1][0] = 2*dp[d][0];
        }else{
            dp[d+1][0] = dp[d][0];
        }
        dp[d+1][0]  %= mod;
    }
    cout << (dp[N][0] + dp[N][1]) % mod << endl;
    return 0;
}