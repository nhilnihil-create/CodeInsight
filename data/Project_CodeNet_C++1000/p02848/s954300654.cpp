#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i, s.size())
    {
        s[i] = s[i] - 'A';
        s[i] = (s[i] + n) % 26;
        s[i] = s[i] + 'A';
    }
    cout << s << endl;
    return 0;
}
