#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    bool playable = true;
    for (size_t i = 0, sz = s.size(); i < sz; ++i) {
        size_t idx = i + 1;
        if (s[i] == 'U' || s[i] == 'D' || (idx % 2 == 0 && s[i] == 'L') || (idx % 2 == 1 && s[i] == 'R')) {
            continue;
        } else {
            playable = false;
        }
    }

    cout << (playable ? "Yes" : "No") << endl;
}