#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t; cin >> s >> t;
    size_t res = t.size();
    for (size_t i = 0; i <= s.size() - t.size(); ++i) {
        size_t diff = 0;
        for (size_t j = 0; j < t.size(); ++j) {
            if (t[j] != s[i + j]) {
                diff++;
            }
        }
        res = min(res, diff);
    }
    cout << res << endl;
}