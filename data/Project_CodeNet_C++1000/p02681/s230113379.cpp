#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    bool ok = s == t.substr(0, s.size());

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
