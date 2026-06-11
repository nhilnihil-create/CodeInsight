#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    ll r, g, b;
    r = count(S.begin(), S.end(), 'R');
    g = count(S.begin(), S.end(), 'G');
    b = count(S.begin(), S.end(), 'B');
    ll all = N * (N - 1) * (N - 2) / 6;
    ll ng = all - r * g * b;    
    for (int j = 0; j < N; j++) {
        for (int k = j + 2; k < N; k += 2) {
            if (S[j] == S[k]) continue;
            int i = (j + k) / 2;
            if (S[j] != S[i] && S[k] != S[i]) ng++;
        }
    }
    cout << all - ng << endl;
    return 0;
}