#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::string S) {
    char before = S[0];
    ll ans = 1;
    for (ll i = 1; i < N; i++) {
        if (S[i] != before) {
            ans++;
        }
        before = S[i];
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
