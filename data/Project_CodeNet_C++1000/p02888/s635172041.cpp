// 6/26 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];

    sort(L.begin(), L.end());

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int maxk = L[i] + L[j] - 1;
            int maxid = upper_bound(L.begin(), L.end(), maxk) - L.begin();
            ans += (maxid-j-1);
        }
    }

    cout << ans << endl;
}