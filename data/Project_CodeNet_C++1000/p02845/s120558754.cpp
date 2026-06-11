#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll mod = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> col(3);
    ll ans = 1;
    int colj;
    rep(i,N) {
        int cnt = 0;
        rep(j,3) {
            if (A[i] == col[j]) {
                ++cnt;
                colj = j;
            }
        }
        ++col[colj];
        ans = (ans * cnt) % mod;
    }
    cout << ans << endl;
}

