#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    
    vector<bool> s(N, false), f(N, false);
    s[A - 1] = true;
    for (int i = A; i < C; ++i) {
        if (S[i] == '#') continue;
        if (i == 1) s[i] = true;
        else if (s[i - 1] || s[i - 2]) s[i] = true;
    }
    f[B - 1] = true;
    for (int i = B; i < D; ++i) {
        if (S[i] == '#') continue;
        if (i == 1) f[i] = true;
        else if (f[i - 1] || f[i - 2]) f[i] = true;
    }
    
    if (C < D) {
        if (s[C - 1] && f[D - 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        bool judge = false;
        REP(i, N - 1) {
            if (f[i] && s[i - 1] && s[i + 1]) judge = true;
        }
        if (judge) {
            if (s[C - 1] && f[D - 1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
