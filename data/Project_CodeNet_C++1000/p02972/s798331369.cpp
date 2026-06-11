#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const long long MOD = 2;

void solve(long long N, std::vector<long long> a) {
    vector<ll> b(N);
    for (ll i = N; i > 0; i--) {
        ll sum = 0;
        for (ll j = i + i; j <= N; j += i) {
            sum ^= b[j - 1];
        }
        b[i - 1] = sum ^ a[i - 1];
    }

    vector<ll> ans;
    for (ll i = 0; i < N; i++) {
        if (b[i]) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
