#include <bits/stdc++.h>
using namespace std;

// これだとなぜかwaになる
int main() {
    int N, K;
    int R, S, P;
    string T;
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;

    long long score = 0;
    vector<bool> winList(N, false);
    for (int i = 0; i < N; i++) {
        if (i >= K) {
            // cout << i << ":" << T[i - K] << "," << T[K] << endl;
            // cout << i - K << ":" << winList[i - K] << endl;
            if (T[i - K] == T[i] && winList[i - K]) {
                winList[i] = false;
                // cout << i << endl; // debug
                continue;
            }
        }

        switch (T[i]) {
            case 'r': {
                score += P;
                break;
            }
            case 's': {
                score += R;
                break;
            }
            case 'p': {
                score += S;
                break;
            }
        }
        // cout << score << endl; // debug
        winList[i] = true;
    }
    cout << score;
}