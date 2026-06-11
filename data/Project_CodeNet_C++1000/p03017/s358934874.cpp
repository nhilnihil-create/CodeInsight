#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool reachable(int u, int v, string S) {
    for (int i = u; i < v; i++) {
        if (S.substr(i, 2) == "##") {
            return false;
        }
    }
    return true;
}

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    A--;
    B--;
    C--;
    D--;

    if (!reachable(A, C, S) || !reachable(B, D, S)) {
        cout << "No" << endl;
        return 0;
    }
    if (C > D) {
        bool ok = false;
        for (int i = B; i <= D; i++) {
            if (S.substr(i - 1, 3) == "...") {
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
