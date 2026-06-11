//解説AC A<<C<<B<<D が考えれてなかった

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--, B--, C--, D--;
    string S;
    cin >> S;

    for (int i = 1; i < N; ++i) {
        if (S.at(i - 1) == '#' && S.at(i) == '#' && ((A <= i && i <= C) || B <= i && i <= D)) {
            cout << "No" << endl;
            exit(0);
        }
    }
    if (C > D) {
        for (int i = B; i <= D; ++i) {
            if (S.at(i - 1) == '.' && S.at(i) == '.' && S.at(i + 1) == '.') {
                cout << "Yes" << endl;
                exit(0);
            }
        }
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
