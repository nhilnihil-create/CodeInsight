// 6/26 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll N, K;
vector<ll> A, F;

bool C(ll x) {
    // xが成立するか？
    ll k = K;

    rep(i, N) {
        if (A[i]*F[i] > x) {
            ll now = x / F[i];
            if (A[i] - now <= k) {
                k -= (A[i] - now);
                // if (k < 0) {
                //     return false;
                // }
            } else {
                return false;
            }
        }
    }
    return true;
}

bool C2(ll x) {
    ll s = 0;
    rep(i, N) {
        s += max(0ll, A[i]-x/F[i]);
    }
    return s <= K;
}

int main() {
    // ll N, K;
    cin >> N >> K;
    // vector<int> A(N), F(N);
    A.resize(N);
    F.resize(N);
    // rep(i, N) cin >> A[i] >> F[i];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];

    ll left = -1;
    ll right = 1000000000000;

    // 消化コストAは降順に
    sort(A.begin(), A.end());
    // 食べにくさFは昇順に
    // sort(F.begin(), F.end(), greater<ll>());
    sort(F.rbegin(), F.rend());

    while (right - left > 1) {
        ll mid = (left + right) / 2;

        if (C(mid)) right = mid;
        else left = mid;
    }

    cout << right << endl;
}