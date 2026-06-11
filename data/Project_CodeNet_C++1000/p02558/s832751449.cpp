#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

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

void solve(long long N, long long Q, std::vector<long long> t,
           std::vector<long long> u, std::vector<long long> v) {
    auto d = dsu(N);
    for (int i = 0; i < Q; i++) {
        if( t[i] == 0 ){
            d.merge(u[i], v[i]);
        }else{
            cout << d.same(u[i], v[i]) << endl;
        }
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> t(Q);
    std::vector<long long> u(Q);
    std::vector<long long> v(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &t[i]);
        scanf("%lld", &u[i]);
        scanf("%lld", &v[i]);
    }
    solve(N, Q, std::move(t), std::move(u), std::move(v));
    return 0;
}
