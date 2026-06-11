#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> A(n), F(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<int>());
    auto f = [&](ll c) {
        ll a = 0;
        rep(i, n) {
            ll b = ll(A[i])*F[i] - c;
            if (b>0) {
                a += (b-1)/F[i] + 1;
            }
        }
        return a <= k;
    };
    ll l = -1, r = 1e13;
    while (r-l > 1) {
        ll m = (l+r) / 2;
        if (f(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}