#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() % 2) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i % 2] != "hi"[i % 2]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}