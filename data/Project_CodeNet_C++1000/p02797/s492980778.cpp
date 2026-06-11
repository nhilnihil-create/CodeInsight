#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, S;
    cin >> N >> K >> S;
    for (int i = 1; i <= K; i++)
        cout << S << " ";
    if (S <= 500000000) {
        for (int i = K + 1; i <= N; i++)
            cout << 2 * S << " ";
    } else {
        for (int i = K + 1; i <= N; i++) {
            cout << 1 << " ";
        }
    }
    cout << endl;
}