#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b;
    cin >> a >> b;

    string s;
    rep (i, max(a, b))
        s.push_back('0' + min(a, b));

    cout << s << endl;
    return 0;
}