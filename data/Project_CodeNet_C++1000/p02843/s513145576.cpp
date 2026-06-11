#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

bool solve(vector<bool> &memo, vector<bool> &visited, ll x) {
    if (x < 0) {
        return false;
    }
    if (visited[x]) {
        return memo[x];
    }

    if (memo[x]) {
        return true;
    } else {
        bool temp = false;
        repd(i, 100, 106) { temp |= solve(memo, visited, x - i); }
        memo[x] = temp;
        visited[x] = true;
        return temp;
    }
}

int main() {
    ll x;
    cin >> x;

    vector<bool> memo(x + 1);
    vector<bool> visited(x + 1);
    visited[0] = true;
    memo[0] = true;

    cout << solve(memo, visited, x) << endl;

    return 0;
}

