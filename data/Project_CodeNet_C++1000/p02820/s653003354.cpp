#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    unordered_map<char, int> table;
    table['r'] = p;
    table['s'] = r;
    table['p'] = s;
    ll ans = 0;
    for (int i = 0; i < k; ++i)
    {
        char prev = t[i];
        ans += table[prev];
        for (int j = i + k; j < n; j += k)
        {
            if (t[j] != prev)
            {
                prev = t[j];
                ans += table[prev];
            }
            else
            {
                prev = 'n';
            }
        }
    }

    cout << ans << endl;
}