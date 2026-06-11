#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    unsigned long long int output = 1;
    int R = 0;
    int G = 0;
    int B = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            R++;
        } else if (S[i] == 'G') {
            G++;
        } else if (S[i] == 'B') {
            B++;
        }
    }
    output *= R;
    output *= G;
    output *= B;
    for (int i = 1; i < (N + 1) / 2; i++) {
        int j = 0;
        while (j + 2 * i < N) {
            if (S[j] != S[j + i] && S[j + i] != S[j + 2 * i] &&
                S[j] != S[j + 2 * i]) {
                // cout << j << " " << j + i << " " << j + 2 * i << endl;
                output--;
            }
            j++;
        }
    }

    cout << output << endl;

    return 0;
}
