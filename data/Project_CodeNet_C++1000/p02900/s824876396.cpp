#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

map<ll, int> mp;

void prime_factorize(long long N) {
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        while (N % a == 0) {
            N /= a;
        }
        ++mp[a];
    }
    if (N != 1) ++mp[N];
}

int main() {
    ll A, B;
    cin >> A >> B;
    prime_factorize(A);
    prime_factorize(B);

    int ans = 1;
    for (auto x : mp) {
        if (x.second >= 2) ++ans;
    }
    cout << ans << endl;
}