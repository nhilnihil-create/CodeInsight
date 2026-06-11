#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    cout << (s == t.substr(0, s.size())? "Yes" : "No") << "\n";
    return 0;
}