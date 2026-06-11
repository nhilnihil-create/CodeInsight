#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P   = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()

void solve(long long N, std::vector<long long> A) {
    i64 g       = A[0];
    rep(i, N) g = gcd(g, A[i]);
    if(g != 1) {
        cout << "not coprime" << endl;
        return;
    }
    bool flag = false;
    sort(all(A));
    rep(i, N - 1) if(A[i] == A[i + 1] && A[i] != 1) flag = true;
    vector<bool> table(1000010, true), exist(1000010);
    rep(i, N) exist[A[i]] = true;
    table[0] = table[1] = false;
    rep(i, 1000000) {
        if(!table[i]) continue;
        i64 cnt = 0;
        if(exist[i]) ++cnt;
        for(int j = 2; i * j <= 1000000; ++j) {
            table[i * j] = false;
            if(exist[i * j]) ++cnt;
        }
        if(cnt >= 2) flag = true;
    }
    if(flag)
        cout << "setwise coprime" << endl;
    else
        cout << "pairwise coprime" << endl;
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
