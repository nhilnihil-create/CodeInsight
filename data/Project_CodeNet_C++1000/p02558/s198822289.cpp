#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(long long N, long long Q, std::vector<long long> t, std::vector<long long> u, std::vector<long long> v){
    atcoder::dsu d(N);
    rep(i, Q){
        if(t[i] == 0) d.merge(u[i], v[i]);
        else{
            if(d.same(u[i], v[i])) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main(){
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> t(Q);
    std::vector<long long> u(Q);
    std::vector<long long> v(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&u[i]);
        scanf("%lld",&v[i]);
    }
    solve(N, Q, std::move(t), std::move(u), std::move(v));
    return 0;
}
