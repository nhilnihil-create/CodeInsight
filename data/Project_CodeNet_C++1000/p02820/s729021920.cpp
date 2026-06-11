#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;

    int ans = 0;
    for (int i = 0; i < K; i++) {
        char last = '.';
        for (int j = i; j < N; j += K) {
            if (T[j] == last) {
                last = '.';
            } else {
                if (T[j] == 'r') ans += P;
                else if (T[j] == 's') ans += R;
                else ans += S;
                last = T[j];
            }
        }
    }

    cout << ans << endl;
}