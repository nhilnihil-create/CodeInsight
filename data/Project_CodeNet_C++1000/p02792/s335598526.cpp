#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll MINF = LLONG_MIN;
const int INT_INF = INT_MAX;

int main()
{
    ll n;
    cin >> n;
    ll cnt[10][10];
    ll res = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cnt[i][j] = 0;
        }
    }
    for (ll k = 0; k < n; k++)
    {
        string s = to_string(k + 1);
        cnt[s[0] - '0'][s[s.length() - 1] - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            res += cnt[i][j] * cnt[j][i];
        }
    }
    cout << res << endl;
}