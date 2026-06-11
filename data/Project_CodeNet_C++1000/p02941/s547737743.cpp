#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_C main
#include "bits/stdc++.h"
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LLONG_MAX/2)
const int MGN = 10;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using psi = pair<string, int>;
// functions 

#endif


int main_C() {
    std::cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vl A(N); REP(i,N) cin >> A[i];
    vl B(N); REP(i,N) cin >> B[i];

    vl x = B;

    priority_queue<pll> pq;
    REP(i, N) pq.push(pll(x[i], i));

    ll ans = 0;
    while(!pq.empty()) {
        int i = pq.top().second; pq.pop();

        if (x[i] < A[i]) break;
        if (x[i] == A[i]) continue;

        ll dx = (x[(i - 1 + N) % N] + x[(i + 1) % N]);
        if (dx == 0) break;

        ll cnt = (x[i] - A[i]) / dx;
        x[i] -= dx * cnt;

        if (cnt > 0) pq.push(pll(x[i], i));
        ans += cnt;
    }

    bool match = true;
    REP(i, N) if (x[i] != A[i]) match = false;

    if (ans > 0 && match) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}