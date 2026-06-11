#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* struct */
struct treasureBox {
    int price;
    int keys;
};
/* global variables */
/* function */
/* main */
int main(){
    int N, K;
    cin >> N >> K;
    vector<treasureBox> B(K);
    for (int i = 0; i < K; i++) {
        int p, m;
        cin >> p >> m;
        B[i].price = p;
        B[i].keys = 0;
        for (int j = 0; j < m; j++) {
            int k; cin >> k;
            k--;
            B[i].keys += (1 << k);
        }
    }

    // dp[s] : 状態sになるための最小円
    vector<int> dp(1<<N, INF);
    dp[0] = 0;
    for (int s = 0; s < 1<<N; s++) {
        for (int i = 0; i < K; i++) {
            int nextS = s | B[i].keys;
            int nextPrice = dp[s] + B[i].price;
            dp[nextS] = min(dp[nextS], nextPrice);
        }
    }
    int ans = dp[(1<<N)-1];
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
