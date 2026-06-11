#include <iostream>
using namespace std;

int main() {
    char s[7]; cin >> s;
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
}

