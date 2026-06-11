#include <bits/stdc++.h>
using namespace std;

bool kaibun(string s) {
    for (int i = 0; i <= (s.size() - 1) / 2; i++) {
        if (s.at(i) != s.at(s.size() - 1 - i))
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool ans = false;
    if (kaibun(s)) {
        if (kaibun(s.substr(0, (n - 1) / 2))) {
            if (kaibun(s.substr((n + 3) / 2 - 1, n))) {
                ans = true;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}