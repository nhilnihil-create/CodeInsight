#include "bits/stdc++.h"
using namespace std;

int32_t main() {
    string s;
    cin >> s;
    int len = s.length();
    if (s[len - 1] == 's')
        s = s + "es";
    else
        s = s + "s";
    cout << s << endl;
}