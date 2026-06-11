#include <bits/stdc++.h>
using namespace std;

int convert(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    return 2;
}
int remain(char c1, char c2) {
    if ((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R')) return 2;
    if ((c1 == 'R' && c2 == 'B') || (c1 == 'B' && c2 == 'R')) return 1;
    return 0;
}

int main() {
    int N; cin >> N;
    string S; cin >> S;
    long long cums[N][3] = {};
    long long ans = 0;

    cums[N-1][convert(S[N-1])] = 1;
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) cums[i][j] = cums[i+1][j];
        cums[i][convert(S[i])]++;
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (S[i] == S[j]) continue;
            ans += cums[j+1][remain(S[i], S[j])];
            int k = 2 * j - i;
            if (k < N && convert(S[k]) == remain(S[i], S[j])) ans--;
        }
    }
    cout << ans << endl;
}