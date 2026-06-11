#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll N, A, B, C, D;
string S;

bool ok(ll s, ll e) {
    for (int i = s; i < e - 1; i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> A >> B >> C >> D;
    --A;
    --B;
    --C;
    --D;
    cin >> S;
    if (!ok(A, C) || !ok(B, D)) {
        cout << "No" << endl;
        return 0;
    }
    if (D > C) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = (B - 1); i < D; i++) {
        if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}