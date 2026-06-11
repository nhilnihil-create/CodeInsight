#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fastio;
    string s;
    cin >> s;
    if (s[s.size()-1] == 's') s += "es";
    else s += "s";
    cout << s;
}
