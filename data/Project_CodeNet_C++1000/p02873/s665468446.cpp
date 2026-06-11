#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::string S) {
    vector<ll> a(S.length() + 1, 0);
    for (ll i = 0; i < S.length(); i++) {
        if (S[i] == '<') {
            a[i + 1] = max(a[i + 1], a[i] + 1);
        }
    }
    for (ll i = S.length() - 1; i >= 0; i--) {
        if (S[i] == '>') {
            a[i] = max(a[i], a[i + 1] + 1);
        }
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
}

int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
