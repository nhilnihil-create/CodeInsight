#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < s.size(); i += 2) {
        if (s[i - 1] != 'h' || s[i] != 'i') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}