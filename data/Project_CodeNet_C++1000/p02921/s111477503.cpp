#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
const long long INF = 1LL << 60;

int main()
{
    string s, t;
    cin >> s >> t;
    int sum = 0;
    rep(i, 3)
    {
        if (s[i] == t[i])
        {
            sum += 1;
        }
    }
    cout << sum << endl;
    return 0;
}
