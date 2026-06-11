#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
//#define int long long
using namespace std;
string s;
main() {
    DAU
    cin >> s;
    if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3])
        cout << "Bad";
    else cout << "Good";
    PLEC
}
