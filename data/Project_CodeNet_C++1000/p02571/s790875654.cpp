#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t; cin >> s >> t;
    int r = t.size();
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        int x = 0;
        for (int j = 0; j < t.size(); j++) {
            x += (s[i + j] != t[j]);
        }
        r = min(r, x);
    }
    cout << r << endl;
    return 0;
}

