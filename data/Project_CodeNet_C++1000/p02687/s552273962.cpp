#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    if (s[1] == 'B') s[1] = 'R';
    else s[1] = 'B';
    cout << s << endl;
    return 0;
}