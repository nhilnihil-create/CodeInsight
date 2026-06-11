#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define all(it) it.begin(), it.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"
lint INF = 2e18;
lint MOD = 1e9 + 7;

lint i, j, k, t;

int main() {
    lint N, K, S;
    cin >> N >> K >> S;

    lint M = 1e9;

    vector<lint> ans(N);
    if(S < M) {
        FOR(i, N) {
            if(i < K) {
                ans[i] = S;
            } else {
                ans[i] = S + 1;
            }
        }
    } else {
        FOR(i, N) {
            if(i < K) {
                ans[i] = S;
            } else {
                ans[i] = 1;
            }
        }
    }

    FOR(i, N) { cout << ans[i] << " "; }
    cout << endl;
}