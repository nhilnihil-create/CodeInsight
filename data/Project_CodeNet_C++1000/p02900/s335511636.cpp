#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for(long long a = 2; a * a <= N; ++a) {
        if(N % a != 0)
            continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while(N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if(N != 1)
        res.push_back({N, 1});
    return res;
}
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }

int main() {
    ll A, B;
    cin >> A >> B;
    ll GCD = gcd(A, B);
    const auto &res = prime_factorize(GCD);
    int ans = 1;
    for(auto p : res) {
        ans++;
    }
    cout << ans << endl;
}
