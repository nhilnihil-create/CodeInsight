#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) + n > 'Z') {
            cout << (char)('A' + (s.at(i) + n - 'Z' - 1));
        } else {
            cout << (char)(s.at(i) + n);
        }
    }

    cout << endl;

    return 0;
}
