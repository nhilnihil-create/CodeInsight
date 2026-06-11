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
    string s, t;
    cin >> s >> t;
    ll N = s.size();
    vector<vector<ll>> dict(N, vector<ll>(26, INF));
    // dict[i][j]:=i文字目以降で、jが初めて出てくる位置
    for(int i = N - 1; i >= 0; i--) {
        if(i != N - 1) {
            rep(j, 26) { dict[i][j] = dict[i + 1][j]; }
        }
        char c = s[i];
        dict[i][c - 'a'] = i;
    }

    ll cur = 0;
    ll res = 0;
    for(int i = 0; i < t.size(); i++) {
        int c = t[i] - 'a';
        if(dict[0][c] == INF) {
            cout << -1 << endl;
            return 0;
        }
        if(dict[cur][c] != INF) {
            cur = dict[cur][c] + 1;
        } else {
            cur = 0;
            res++;
            cur = dict[cur][c] + 1;
        }
        if(cur >= N) {
            cur = 0;
            res++;
        }
    }
    cout << res * N + cur << endl;

    return 0;
}