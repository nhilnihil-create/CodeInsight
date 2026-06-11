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
    vector<int> A(N+1);
    rep(i, N+1) cin >> A[i];
    vector<int> B(N);
    rep(i, N) cin >> B[i];
    ll ans = 0;
    rep(i, N) {
        int temp = min(A[i], B[i]);
        A[i] -= temp; B[i] -= temp;
        temp += min(A[i+1], B[i]);
        A[i+1] -= min(A[i+1], B[i]);
        ans += temp;
    }
    cout << ans << '\n';
    return 0;
}