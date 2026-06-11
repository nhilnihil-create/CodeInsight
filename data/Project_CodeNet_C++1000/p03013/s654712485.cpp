#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

#define MOD 1000000007

int N;

int main(){

    int N; cin >> N;
    int M; cin >> M;

    vector<bool> safe(N+1, true);
    vector<int> dp(N+10, 0);

    int m;
    for(int i = 0; i < M; ++i){
        cin >> m;
        safe[m] = false;
    }

    dp[0] = 0;

    if(safe[1]) dp[1] = 1;
    if(safe[1] && safe[2]) dp[2] = 2;
    if(!safe[1] && safe[2]) dp[2] = 1;

    for(int i = 3; i < N+5; i++){
        if(safe[i]) dp[i] += dp[i-1] %MOD;
        if(safe[i]) dp[i] += dp[i-2] % MOD;
    }

    cout << dp[N] % MOD << endl;
}