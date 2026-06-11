#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if (s.compare(u) == 0)
        a--;
    else
        b--;
    cout << a << " " << b << endl;
    return 0;
}