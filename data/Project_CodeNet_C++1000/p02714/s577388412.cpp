#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    ll R = 0, G = 0, B = 0;
    for (auto e : S) {
        if (e == 'R') ++R;
        else if (e == 'G')
            ++G;
        else if (e == 'B')
            ++B;
    }

    ll ans = R * G * B;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = 1; i + j + j < N; ++j) {
            if (S[i] != S[i + j] && S[i + j] != S[i + j + j]
                && S[i] != S[i + j + j])
                --ans;
        }
    }
    cout << ans << '\n';
}
