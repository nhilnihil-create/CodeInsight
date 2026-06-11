#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    deque<char> dq;
    for (auto c : s) dq.emplace_back(c);
    bool rev = 0;
    int q;
    cin >> q;
    while (q--) {
        int t, f;
        char c;
        cin >> t;
        if (t == 1) {
            rev = !rev;
        } else {
            cin >> f >> c;
            if ((f == 1 && !rev) || (f == 2 && rev)) dq.emplace_front(c);
            else dq.emplace_back(c);
        }
    }
    if (rev) reverse(dq.begin(), dq.end());
    for (auto c : dq) cout << c;
    cout << "\n";
}
