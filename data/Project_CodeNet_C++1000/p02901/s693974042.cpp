#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> key(M);
    vector<int> price(M);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        price[i] = a;
        int num = 0;
        rep(i, b) {
            int c;
            cin >> c;
            c--;
            num |= (1 << c);
        }
        key[i] = num;
    }
    vector<ll> dp(1 << N, INF);
    dp[0] = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        for(int i = 0; i < M; i++) {
            dp[bit | key[i]] = min(dp[bit | key[i]], dp[bit] + price[i]);
        }
    }
    if(dp[(1 << N) - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[(1 << N) - 1] << endl;
    return 0;
}