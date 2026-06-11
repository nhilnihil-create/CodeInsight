#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

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

ll dp[2020][2020]; //dp[i][j] = Sのi番目、Tのj番目までの部分列の組であって、整数列として等しいような組の個数

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> S(N);
    for(int i = 0;i < N;i++) {
        cin >> S.at(i);
    }
    vector<int> T(M);
    for(int i = 0;i < M;i++) {
        cin >> T.at(i);
    }
    for(int i = 0;i < 2020;i++) {
        for(int j = 0;j < 2020;j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            if(S.at(i) == T.at(j)) {
                dp[i + 1][j + 1] = mod(dp[i][j + 1] + dp[i + 1][j]);
            }
            else {
                dp[i + 1][j + 1] = mod(dp[i][j + 1] + dp[i + 1][j] - dp[i][j]);
            }
        }
    }
    cout << dp[N][M] % MOD << endl;
}