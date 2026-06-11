#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define no {cout << -1; return;}

const int MOD = 1e9 + 7, N = 1e5 + 7;

int two[N] = { 1 }, three[N] = { 1 };

void solve() {
    loop1(i, N - 1) {
        two[i] = two[i - 1] * 2 % MOD;
        three[i] = three[i - 1] * 3 % MOD;
    }
    string s; cin >> s;
    int ans = 1;
    loop(i, s.size() - 1)
        ans = (ans + 2 * three[i]) % MOD;
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i)
        if (s[i] == '1')
            ans = (ans + two[cnt++] * three[s.size() - 1 - i]) % MOD;
    ans = (ans + two[cnt]) % MOD;
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}