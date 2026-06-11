#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    bool rev = false;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            rev = 1 - rev;
        } else {
            int f;
            char t;
            cin >> f >> t;
            if (f == 1) {
                if (rev)
                    s += t;
                else
                    s = t + s;
            } else {
                if (rev)
                    s = t + s;
                else
                    s += t;
            }
        }
    }
    s = rev ? string(s.rbegin(), s.rend()) : s;
    cout << s;
}