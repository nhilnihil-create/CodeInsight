#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

bool reach(int start, int goal, string S) {
    rep2(i, start, goal+1) {
        if (S[i] == '#' && S[i+1] == '#') {
            return false;
        }
    }
    return true;
}

int main() {
    int N, A , B , C , D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    S = '#' + S + 'S';
    if (!reach(A, C, S) || !reach(B, D, S)) {
        cout << "No" << endl;
        return 0;
    }

    if (C > D) {
        bool skip = false;
        rep2(i, B, D+1) {
            if (S[i-1] == '.' && S[i] == '.' && S[i+1] == '.') {
                skip = true;
            }
        }
        if (!skip) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}