#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
 
template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int dp[200020][3] = {0};

int main() {
    string S;
    cin >> S;
    int N = S.size();
    S += "####";
    dp[1][0] = dp[2][1] = 1;
    for(int i = 0;i < N;i++) {
        if(i >= 1 && S.at(i - 1) != S.at(i)) {
            dp[i + 1][1] = max(dp[i + 1][1],dp[i][1] + 1);
        }
        if(i >= 2 && (S.at(i - 2) != S.at(i) || S.at(i - 1) != S.at(i + 1))) {
            dp[i + 2][2] = max(dp[i + 2][2],dp[i][2] + 1);
        }
        dp[i + 2][2] = max(dp[i + 2][2],dp[i][1] + 1);
        dp[i + 1][1] = max(dp[i + 1][1],dp[i][2] + 1);
    }
    cout << max(dp[N][1],dp[N][2]) << endl;
}