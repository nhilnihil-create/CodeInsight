#include <bits/stdc++.h>


using namespace std;


int main() {
    long long N;
    string S;
    cin >> N >> S;

    map<char, long long> c;
    c['R'] = 0;
    c['G'] = 0;
    c['B'] = 0;

    for (auto ch : S) {
        c[ch] += 1;
    }

    long long remove = 0;
    for (long long d = 1; d <= (N - 1) / 2; d++) {
        for (long long i = 0; i < S.length() - 2 * d; i++) {
            long long j, k;
            j = i + d;
            k = j + d;
            if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) {
                remove++;
            }
        }
    }
    long long ans = c['R'] * c['G'] * c['B'] - remove;
    cout << ans << endl;
}
