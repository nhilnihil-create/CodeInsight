#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    ll left = 0, right = 0;
    rep(i, N) {
        cin >> vec[i];
        right += vec[i];
    }
    ll mini = 1e18;
    rep(i, N) {
        mini = min(mini, abs(left - right));
        left += vec[i];
        right -= vec[i];
    }
    cout << mini << endl;
    return 0;
}