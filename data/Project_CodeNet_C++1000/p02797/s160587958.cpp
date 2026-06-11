#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, S;
    cin >> N >> K >> S;

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        if (K) {
            cout << S;
            K--;
        } else {
            cout << int(1e9 - (S == 1e9));
        }
    }
    cout << endl;

    return 0;
}