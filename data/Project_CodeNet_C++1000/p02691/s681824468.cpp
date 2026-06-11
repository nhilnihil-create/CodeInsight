#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    vector<int> B(n);
    rep(i, n) B[i] = A[i] - i;
    sort(B.begin(), B.end());
    ll ans = 0;
    rep (i, n) {
        int a = upper_bound(B.begin(), B.end(), -A[i]-i) - lower_bound(B.begin(), B.end(), -A[i]-i);
        ans += a;
    }
    cout << ans << endl;
    return 0;
}