#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int k;
string s;
int main() {
    DAU
    cin >> k >> s;
    for (char& c : s)
        c = (c - 'A' + k) % 26 + 'A';
    cout << s;
    PLEC
}
