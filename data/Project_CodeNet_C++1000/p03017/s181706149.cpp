#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
int main() {
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    S = "#" + S + "#";
    auto t = [&](int start , int end) {
        for (int i = start; i + 1 <= end; i++) {
            if (S[i] == '#' && S[i + 1] == '#'){
                return false;
            }
        }
        return true;
    };

    if (!t(A, C) || !t(B, D)) {
        cout << "No" << endl;
        return 0;
    }

    if (C > D) {
        bool h = false;
        for (int i = B; i <= D; i++) {
            if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
                h = true;
            }
        }
        if (!h) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
