#include <bits/stdc++.h>

using namespace std;

#define Vi vector<int>
#define FOR(i,s,e) for (int i=s; i<e; i++)
#define ITER(v) v.begin(), v.end()

constexpr int N_MAX = 44;

int dp[N_MAX+1] = {};

int fib(int n) {
    if (n == 0 || n == 1) { return 1; }
    if (dp[n]) { return dp[n]; }
    int res = fib(n-1) + fib(n-2);
    dp[n] = res;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}