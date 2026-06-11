#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    string s;
    cin >> s;
    bool bad = false;
    if (s[0] == s[1]) bad = true;
    if (s[1] == s[2]) bad = true;
    if (s[2] == s[3]) bad = true;
    if (bad) cout << "Bad" << endl;
    else cout << "Good" << endl;
    return 0;
}