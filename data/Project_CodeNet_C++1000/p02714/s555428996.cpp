// 6/17 振り返り
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    ll res = 0;

    ll r, g, b;
    r = g = b = 0;

    // for (int i = 0; i < N; i++) {
    //     for (int j = i + 1; j < N; j++) {
    //         for (int k = j + 1; k < N; k++) {
    //             if (j - i == k - j) continue;
    //             if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) res++;
    //         }
    //     }
    // }

    for (auto s : S) {
        if (s == 'R') r++;
        else if (s == 'G') g++;
        else b++;
    }

    res = r * g * b;
    // cout << res << endl;

    // for (int delta = 1; delta <= (N + 1) / 2; delta++) {
    //     for (int i = 0; i + 2 * delta < N; i++) {
    //         // cout << "here?" << endl;
    //         int j = i + delta;
    //         int k = j + delta;
    //         // printf("i, j, k = %d, %d, %d\n", i, j, k);
    //         if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) res--;
    //     }
    // }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int k = 2 * j - i;
            if (k < N) {
                if ((S[i] != S[j]) && (S[j] != S[k]) && (S[k] != S[i])) res--;
            }
        }
    }

    cout << res << endl;
}
