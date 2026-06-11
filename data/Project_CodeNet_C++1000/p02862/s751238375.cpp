#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 1e6;
int n, m;
vi fact(maxn), finv(maxn), inv(maxn);

void COMinit() {
    fact.assign(2, 1);
    finv.assign(2, 1);
    inv.assign(2, 1);
    FOR(i, 2, maxn) {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = mod - (inv[mod%i] * (mod/i)) % mod;
        finv[i] = (finv[i-1] * inv[i]) % mod;
    }
}

int COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fact[n] * ((finv[k] * finv[n-k]) % mod)) % mod;
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    // https://atcoder.jp/contests/abc034/tasks/abc034_c
    cin >> n >> m;
    if (n > m) swap(n, m);

    int dif = m - n;
    int com = n - dif;
    if (com % 3 != 0) {
        cout << 0 << "\n";
    } else {
        COMinit();
        com /= 3;
        cout << COM(2*com + dif, com) << "\n";
    }

}