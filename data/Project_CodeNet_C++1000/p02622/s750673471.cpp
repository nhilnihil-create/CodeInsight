#include <iostream>
using namespace std;
int main() {
    string s{}, t{};
    size_t ans{};
    cin >> s >> t;
    for (size_t i{}; i < s.length(); i++) if (s[i] != t[i]) ans++;
    cout << ans;
}