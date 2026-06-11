#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s, t, u;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    cin >> u;
    if (s == u) a--;
    if (t == u) b--;
    cout << a << " " << b << endl;
    return 0;
}