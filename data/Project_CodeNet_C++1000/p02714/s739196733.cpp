#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    long long cntR = 0, cntG = 0, cntB = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') cntR++;
        else if (S[i] == 'G') cntG++;
        else cntB++;
    }

    long long ans = cntR * cntG * cntB;
    for (int i = 0; i + 2 < N; i++) {
        for (int j = i + 1; j + 1 < N; j++) {
            if (S[i] == S[j]) continue;
            int k = 2 * j - i;
            if (k >= N || S[i] == S[k] || S[j] == S[k]) continue;
            ans--;
        }
    }

    cout << ans << endl;
}