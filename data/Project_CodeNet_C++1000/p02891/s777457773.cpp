#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    long long int K;
    cin >> S;
    cin >> K;

    bool same = true;

    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] != S[i + 1]) {
            same = false;
        }
    }
    if (same) {
        long long int output = K * S.size() / 2;
        cout << output << endl;
        return 0;
    }

    long long int num = 0;
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] == S[i + 1]) {
            num++;
            i += 1;
        }
    }

    string S2 = S + S;
    long long int num2 = 0;
    for (int i = 0; i < S2.size() - 1; i++) {
        if (S2[i] == S2[i + 1]) {
            num2++;
            i += 1;
        }
    }

    long long int output;

    output = num + (K - 1) * (num2 - num);

    cout << output << endl;

    return 0;
}
