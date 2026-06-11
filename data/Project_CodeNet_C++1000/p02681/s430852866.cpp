#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int flag = 1;
    if (s.size() + 1 == t.size()) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                flag = 0;
            }
        }
    }

    flag == 1 ? cout << "Yes" : cout << "No";

    return 0;
}