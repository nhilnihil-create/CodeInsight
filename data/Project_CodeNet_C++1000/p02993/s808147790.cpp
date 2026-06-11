#include <cctype>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i && s[i] == s[i - 1]) {
            cout << "Bad";
            return 0;
        }
    }
    cout << "Good";
    return 0;
}
