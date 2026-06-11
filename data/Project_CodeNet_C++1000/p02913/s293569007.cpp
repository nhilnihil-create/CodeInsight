#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int dp[5050][5050];

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    for(int i = 0;i <= N;i++) {
        dp[N + 1][0] = 0;
        dp[0][N + 1] = 0;
    }
    for(int i = N;i >= 1;i--) {
        for(int j = N;j >= 1;j--) {
            if(S.at(i - 1) == S.at(j - 1)) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    int ret = 0;
    for(int i = 1;i <= N;i++) {
        for(int j = i;j <= N;j++) {
            int cnt = min(dp[i][j],j - i);
            ret = max(ret,cnt);
        }
    } 
    cout << ret << endl;
}  