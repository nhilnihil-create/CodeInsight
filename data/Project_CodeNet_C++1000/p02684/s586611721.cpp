#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    ll k;
    cin >> n;
    cin >> k;
    vector<vector<int>> next(60, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> next[0][i];
        next[0][i]--;
    }

    for (int i = 0; i < 59; ++i) {
        for (int j = 0; j < n; ++j) {
            next[i+1][j] = next[i][next[i][j]];
        }
    }

    int res = 0;
    for (int i = 0; i < 60; ++i) {
        if (k & 1) res = next[i][res];
        k >>= 1;
    }

    cout << res + 1 << endl;
}