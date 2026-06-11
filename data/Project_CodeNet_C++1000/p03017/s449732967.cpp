#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, A, B, C, D;
string S;

bool ok(int s, int e) {
    for (int i = s; i <= e-1; i++) {
        if (S[i] == '#' && S[i+1] == '#') return false;
    }
    return true;
}

int main() {
    cin >> N >> A >> B >> C >> D;
    cin >> S;
    S = '#' + S + '#';

    if (!ok(A, C) || !ok(B, D)) {
        cout << "No" << endl;
        return 0;
    }
    
    if (C > D) {
        bool flag = false;
        for (int i = B; i <= D; i++) {
            if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') flag = true;
        }
        if (!flag) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
