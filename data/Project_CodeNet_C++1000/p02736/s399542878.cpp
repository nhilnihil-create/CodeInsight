#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string s;
    cin >> s;
    bool has_1 = false;
    valarray<int> vals(N);
    for (int i = 0; i < N; i++) {
        vals[i] = s[i] - '1';
        has_1 |= vals[i] == 1;
    }
    if (has_1)
        vals %= 2;
    else
        vals /= 2;
    bool parity = 0;
    for (int i = 0; i < N; i++) {
        parity ^= vals[i] && ((N - 1) | i) == N - 1;
    }
    cout << (parity ? (has_1 ? 1 : 2) : 0) << endl;
}
