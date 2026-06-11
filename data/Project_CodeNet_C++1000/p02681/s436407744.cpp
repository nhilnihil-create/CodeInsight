#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    if (s.size() + 1 != t.size()) {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) != t.at(i)) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
