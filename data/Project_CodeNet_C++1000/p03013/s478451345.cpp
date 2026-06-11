#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, m; cin >> n >> m;
    V<int> b(n + 1);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        b[a] = 1;
    }

    V<int> dp(n + 2);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(b[i]){
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
    }
    cout << dp[0] << endl;


    return 0;
}
