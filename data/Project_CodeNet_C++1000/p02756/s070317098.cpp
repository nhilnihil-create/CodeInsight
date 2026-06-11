#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;

    bool r = false;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            r = !r;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                r ? s += c : s = c + s;
            } else {
                r ? s = c + s : s += c;
            }
        }
    }

    if (r) reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
