#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    int divisors[N + 1] = {0};
    for(int i = 1; i <= N; i++) {
        for(int j = 1; i * j <= N; ++j) {
            ++divisors[i * j];
        }
    }

    ll res = 0;
    for(int i = 1; i <= N; i++) {
        res += ll(i) * divisors[i];
    }
    cout << res << endl;

    return 0;
}
