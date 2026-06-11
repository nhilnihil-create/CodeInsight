//
// Created by Hideaki Imamura on 2020-03-23.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1LL << 60)
# define PI (acos(-1))
//const ll mod = 1000000007;

ll N, K;
vector<ll> A, F;

bool is_ok(ll x) {
    ll sum = 0;
    for (int i = 0; i < N; ++i) sum += max(0ll, A[i] - x / F[i]);
    return (sum <= K);
}

int main() {
    cin >> N >> K;
    A.resize(N);
    F.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    ll l = -1, r = INF;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (is_ok(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}