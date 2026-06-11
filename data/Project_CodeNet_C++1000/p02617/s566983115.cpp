#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(long long N, std::vector<long long> u, std::vector<long long> v) {

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += 1ll * (i + 1) * (N - i);
    }
    for (int i = 0; i < N - 1; i++) {
        ans -= 1ll * min(u[i], v[i]) * (N - max(u[i], v[i]) + 1);
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> u(N - 1);
    std::vector<long long> v(N - 1);
    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &u[i]);
        scanf("%lld", &v[i]);
    }
    solve(N, std::move(u), std::move(v));
    return 0;
}
