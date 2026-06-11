#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

int main() {
    list<char> ans;
    string S;
    ll Q;
    bool swap = false;
    cin >> S >> Q;
    rep(i, S.length()) { ans.push_back(S[i]); }
    rep(i, Q) {
        ll T;
        cin >> T;
        if (T == 1) {
            swap = !swap;
        } else {
            ll F;
            char C;
            cin >> F >> C;
            if (F == 1) {
                if (!swap) {
                    ans.push_front(C);
                } else {
                    ans.push_back(C);
                }
            } else {
                if (!swap) {
                    ans.push_back(C);
                } else {
                    ans.push_front(C);
                }
            }
        }
    }
    if (swap) {
        ans.reverse();
    }
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i;
    }
    cout << endl;
    return 0;
}
