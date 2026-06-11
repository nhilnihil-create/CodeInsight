#include <algorithm>
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
    int h, n; cin >> h >> n;
    V<int> dp(h + 1, 1001001001);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        for(int j = 0; j < h; j++){
            int nj = min(j + a, h);
            dp[nj] = min(dp[nj], dp[j] + b);
        }
    }
    cout << dp[h] << endl;

    return 0;
}
