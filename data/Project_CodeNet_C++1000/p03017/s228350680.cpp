#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

void forward(const string& S, int& B) {
    if (S[B+1] != '#') {
        B++;
        return;
    } else if (S[B+2] != '#') {
        B+=2;
        return;
    }
    cout << "No" << endl;
    exit(0);
}

int main() {
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    A--, B--, C--, D--;
    string S; cin >> S;

    if (A < B && C > D) { // Must jump over
        while (B < D && (S[B-1] == '#' || S[B+1] == '#')) forward(S, B);
        if (B == D) S[B] = '#';
        if (B > D) {
            cout << "No" << endl;
            return 0;
        }
        while (A != C) forward(S, A);
        S[C] = '#';
    }

    if (B != D) {
        while (B != D) forward(S, B);
    }
    if (A != C) {
        while (A != C) forward(S, A);
    }
    cout << "Yes" << endl;
}
