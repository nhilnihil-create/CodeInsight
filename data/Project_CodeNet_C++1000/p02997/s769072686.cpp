#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
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

const int MAX_C = 1000;
long long Com[MAX_C][MAX_C];
void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for(int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for(int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]) % MOD;
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    calc_com();
    if(K > Com[N - 1][2]) {
        cout << -1 << endl;
        return 0;
    }
    int M = Com[N - 1][2] + N - 1 - K;
    vector<pii> res;
    for(int i = 1; i < N; i++) {
        res.pb(MP(1, i + 1));
    }
    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            res.pb(MP(i + 1, j + 1));
        }
    }
    cout << M << endl;
    rep(i, M) { cout << res[i].first << " " << res[i].second << endl; }

    return 0;
}