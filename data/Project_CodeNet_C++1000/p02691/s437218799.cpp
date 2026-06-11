#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    map<int, int> mp;
    rep(i, N) {
        ++mp[A[i] + i];
        ans += mp[-A[i] + i];
    }

    cout << ans << endl;
}