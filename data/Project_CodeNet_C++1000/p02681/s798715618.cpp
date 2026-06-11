#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;
    if (t.substr(0,s.size())==s) cout << "Yes";
    else cout << "No";
    return 0;
}