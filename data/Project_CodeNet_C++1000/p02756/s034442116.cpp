#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S = "";
    cin >> S;
    deque<char> deq(S.size());
    rep(i, S.size()) { deq[i] = S[i]; }
    ll Q;
    int rev = 0;
    cin >> Q;
    rep(i, Q) {
        int T;
        cin >> T;
        if(T == 1) {
            rev = 1 - rev;
        } else {
            int F;
            char C;
            cin >> F >> C, --F;
            if(rev)
                F = 1 - F;
            if(F == 0) {
                deq.push_front(C);
            } else {
                deq.push_back(C);
            }
        }
    }
    if(rev) {
        reverse(deq.begin(), deq.end());
    }
    for(auto c : deq) {
        cout << c;
    }
    cout << endl;
    return 0;
}