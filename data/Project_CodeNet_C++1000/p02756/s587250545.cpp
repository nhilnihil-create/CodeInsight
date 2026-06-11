#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    deque<char> dS(S.size());
    for (int i = 0; i < S.size(); ++i) dS[i] = S[i];

    int Q; cin >> Q;
    int rev = 0;
    for (int i = 0; i < Q; ++i) {
        int type; cin >> type;
        if (type == 2) {
            int f; char c;
            cin >> f >> c; --f;
            if (rev) f = 1 - f; // 反転状態だったら、フラグを反転
            if (f == 0) dS.push_front(c);
            else dS.push_back(c);
        }
        else rev = 1 - rev;
    }
    if (rev) reverse(dS.begin(), dS.end());
    for (auto c : dS) cout << c;
    cout << endl;
}