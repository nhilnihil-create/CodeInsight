#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    string s;
    rep(i, n)
    {
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    ll tmp;
    ll res = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        ll f = itr->second;
        tmp = f * (f - 1) / 2;
        res += tmp;
    }
    cout << res << endl;

    return 0;
}