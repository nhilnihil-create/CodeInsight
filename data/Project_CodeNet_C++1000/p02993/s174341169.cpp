#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if (s[0] == s[1]) cout << "Bad" << endl;
    else if (s[1] == s[2]) cout << "Bad" << endl;
    else if (s[2] == s[3]) cout << "Bad" << endl;
    else cout << "Good" << endl;
}