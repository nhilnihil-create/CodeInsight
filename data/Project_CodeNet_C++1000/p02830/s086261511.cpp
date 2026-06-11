#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    rep(i, n) cout << s[i] << t[i];
    cout << endl;
}