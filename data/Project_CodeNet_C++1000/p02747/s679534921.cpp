#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool ok = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i & 1) {
            if (s[i] != 'i') {
                ok = 0;
            }
        } else {
            if (s[i] != 'h') {
                ok = 0;
            }
        }
    }
    if (s.size() & 1) ok = 0;
    puts(ok ? "Yes" : "No");
    return 0;
}