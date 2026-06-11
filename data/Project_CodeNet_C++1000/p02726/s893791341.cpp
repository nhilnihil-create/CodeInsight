#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<ll> cnt(N, 0);
    for (ll i = 1; i < N; i++) {
        for (ll j = i + 1; j <= N; j++) {
            ll len;
            if (i <= X && Y <= j) {
                len = j - i - (Y - X - 1);
            } else if (i <= X && j < Y) {
                ll sc = X - i + 1 + (Y - j);
                len = min(sc, j - i);
            } else if (X < i && Y <= j) {
                ll sc = i - X + 1 + (j - Y);
                len = min(sc, j - i);
            } else if (X < i && j < Y) { 
                ll sc = i - X + 1 + (Y - j);
                len = min(sc, j - i);
            }else {
                len = j - i;
            }
            cnt[len]++;
        }
    }

    for (ll i = 1; i < N; i++) {
        cout << cnt[i] << endl;
    }
}
