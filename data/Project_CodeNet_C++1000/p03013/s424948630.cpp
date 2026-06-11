#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
#define Graph vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
#define inf 1000000321
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll dp[201000];

int main(){
    int N,M;
    cin >> N >> M;
    vector<bool> S(N);
    for(int i = 0;i < M;i++){
        int a;
        cin >> a;
        S[a] = true;
    }
    ll ans = 0;
    dp[0] = 1;
    if(!S[1])dp[1] = 1;
    
    for(int i = 2;i <= N;i++){
        if(!S[i-2])dp[i] += dp[i-2];
        if(!S[i-1])dp[i] += dp[i-1];
        dp[i] %= mod107;
    }

    cout << dp[N] % mod107 << endl;
}