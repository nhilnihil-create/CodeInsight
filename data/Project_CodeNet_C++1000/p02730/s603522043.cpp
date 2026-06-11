#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;

    auto s1 = s.substr(0, (s.size() - 1) / 2);
    auto s2 = s.substr((s.size() + 3) / 2 - 1);
    reverse(s2.begin(), s2.end());

    auto s11 = s1.substr(0, (s1.size() + 1) / 2);
    auto s12 = s1.substr((s1.size() + 2) / 2 - 1);
    reverse(s12.begin(), s12.end());

    auto s21 = s2.substr(0, (s2.size() + 1) / 2);
    auto s22 = s2.substr((s2.size() + 2) / 2 - 1);
    reverse(s22.begin(), s22.end());

    cout << (s1 == s2 && s11 == s12 && s21 == s22 ? "Yes" : "No") << endl;
}

