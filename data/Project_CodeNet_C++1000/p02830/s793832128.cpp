#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string res = "";
    for (auto i = 0; i < n; ++i) {
        res += s[i];
        res += t[i];
    }

    cout << res << "\n";
}