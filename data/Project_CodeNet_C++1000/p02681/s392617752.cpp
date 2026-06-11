#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    if (equal(s.begin(), s.end(), t.begin(), t.end() - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}