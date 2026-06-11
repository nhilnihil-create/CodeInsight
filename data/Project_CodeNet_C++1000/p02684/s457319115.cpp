#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<vector<int>> next(60, vector<int>(N));

    rep(i, N) {
        cin >> next[0][i];
        next[0][i]--;
    }

    for (int d = 0; d + 1 < 60; d++) {
        for (int v = 0; v < N; v++) {
            next[d + 1][v] = next[d][next[d][v]];
        }
    }

    int v = 0;
    for (int d = 0; d < 60; d++) {
        if (K & (1LL << d))
            v = next[d][v];
    }

    cout << v + 1 << endl;
}