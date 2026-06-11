#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    const ll c = 1000000007;
    int N, M;
    cin >> N >> M;
    vector<ll> dp(N+1, 1);
    for(int i=0; i<M; i++) {
        int broken;
        cin >> broken;
        dp[broken] = 0;
    }
    for(int i=2; i<=N; i++) {
        if(dp[i] == 0) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % c;
    }
    cout << dp[N] << endl;
}