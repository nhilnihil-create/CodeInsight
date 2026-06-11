#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += s[i] - '0';
    }
    if (ans % 9 == 0) {
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    return 0;
}
