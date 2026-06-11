#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(1000001, -1);
    sort(A.begin(), A.end());
    rep(i, N) {
        int x = A[i];
        if (B[x] == 1) continue;
        B[x]++;
        for (int j = x * 2; j <= 1000001; j += x) {
            B[j] = 1;
        }
    }
    ll ans = 0;
    for (int x : A) {
        if (B[x] == 0) ans++;
    }
    cout << ans << '\n';
    return 0;
}