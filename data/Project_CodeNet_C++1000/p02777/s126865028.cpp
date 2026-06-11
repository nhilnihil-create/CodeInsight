#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;

    if(u == s) a--;
    else b--;

    cout << a << " " << b << "\n";
    return 0;
}
