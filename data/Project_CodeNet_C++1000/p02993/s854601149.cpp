#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char last = '\0';
    bool bad = false;
    for (auto c : s) {
        if (last && c == last) {
            cout << "Bad\n";
            bad = true;
            break;
        }
        last = c;
    }
    if (!bad)
        cout << "Good\n";
}