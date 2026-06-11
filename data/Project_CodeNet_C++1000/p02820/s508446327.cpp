#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    string hand = "";
    for (int i = 0; i < K; i++) {
        hand += "a";
    }

    int score = 0;

    for (int i = 0; i < N; i++) {
        if (T[i] == 'r') {
            if (hand[i] != 'p') {
                hand += "p";
                score += P;
            } else {
                hand += "a";
            }
        } else if (T[i] == 'p') {
            if (hand[i] != 's') {
                hand += "s";
                score += S;
            } else {
                hand += "a";
            }
        } else {
            if (hand[i] != 'r') {
                hand += "r";
                score += R;
            } else {
                hand += "a";
            }
        }
    }

    cout << score << endl;

    return 0;
}
