#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S, C;
    int Q, T, F;
    cin >> S >> Q;
    int rev = 1;

    rep(i,Q) {
        cin >> T;
        if (T == 1) {
            rev *= -1;
        } else if (T == 2) {
            cin >> F >> C;
            if ((F == 1 && rev == 1) 
            || (F == 2 && rev == -1)) {
                S.insert(0, C);
            } else {
                S.insert(S.size(), C);
            }
        }
    }
    if (rev == -1) reverse(S.begin(), S.end());
    cout << S << endl;
}
