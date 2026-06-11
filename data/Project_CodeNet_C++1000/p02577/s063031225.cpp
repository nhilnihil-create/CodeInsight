#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    int x = 0;
    for (char i : s) {
        x += i - '0';
    }
    cout << (x % 9 ? "No" : "Yes") << endl;
    return 0;
}

