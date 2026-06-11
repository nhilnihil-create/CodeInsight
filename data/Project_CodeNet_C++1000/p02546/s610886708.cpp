#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    if (s[s.size()-1] != 's')
        s += "s";
    else
        s += "es";
    cout << s << "\n";
}