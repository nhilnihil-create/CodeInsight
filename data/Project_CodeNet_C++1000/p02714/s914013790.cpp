//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    string S; cin >> S;

    long long r = 0, g = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') r++;
        if (S[i] == 'G') g++;
        if (S[i] == 'B') b++;
    }

    long long cnt = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            if (S[i] != S[j]) {
                int k = j + (j-i);
                if (k < N) {
                    if (S[i] != S[k] && S[j] != S[k]) {
                        cnt++;
                    }
                }
            }
        }
    }

    long long ans = r * g * b - cnt;

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}