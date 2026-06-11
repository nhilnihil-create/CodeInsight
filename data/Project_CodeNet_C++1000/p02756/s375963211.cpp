#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    deque<char> dq;
    rep(i, S.size()) {
        dq.push_back(S[i]);
    }
    int Q;
    cin >> Q;
    bool rev = false;
    rep(i, Q) {
        int T;
        cin >> T;
        if (T == 1) {
            rev = !rev;
        } else {
            int F;
            char C;
            cin >> F >> C;

            if ((F == 1 && !rev) || (F == 2 && rev)) {
                dq.push_front(C);
            } else {
                dq.push_back(C);
            }
        }
        /*
        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it;
        }
        cout << endl;*/
    }
    string S2;
    if (!rev) {
        for (auto it = dq.begin(); it != dq.end(); it++) {
            S2.push_back(*it);
        }
    } else {
        for (auto it = dq.rbegin(); it != dq.rend(); it++) {
            S2.push_back(*it);
        }
    }
    cout << S2 << endl;

             
    return 0;
}
