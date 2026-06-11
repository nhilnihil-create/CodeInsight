#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[s.length() - 1] == 's') {
        s.append("es");
    } else {
        s.append("s");
    }
    cout << s;
    return 0;
}