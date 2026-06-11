#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        P[i] = p - 1;
    }
    for (int i = 0; i < N; i++) cin >> C[i];
    ll ans = -1e9;
    for (int s = 0; s < N; s++) {
        int i = s;
        ll c = 0;
        vector<ll> score;
        do {
            c += C[i];
            score.push_back(c);
            i = P[i];
        } while (i != s);
        for (int i = 0; i < min((int) score.size(), K); i++) {
            ans = max(ans, score[i]);
            ans = max(ans, score[i] + (K - i - 1) / (int) score.size() * score.back());
        }
    }
    cout << ans << endl;
}