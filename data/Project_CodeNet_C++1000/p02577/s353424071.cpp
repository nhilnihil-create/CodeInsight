#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int)s.length() && s[i] != '\0'; i++) {
        sum += s[i] - '0';
    }
    if (sum % 9 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
