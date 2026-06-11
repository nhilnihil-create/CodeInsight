#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    vector<string> str(N);
    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    unordered_map<string, ll> pattern;
    for (int i = 0; i < N; i++)
    {
        sort(str[i].begin(), str[i].end());
        if (pattern.count(str[i]))
        {
            pattern[str[i]] += 1;
        }
        else
        {
            pattern[str[i]] = 1;
        }
        // ans += pattern[str[i]] - 1;
    }

    ll ans = 0;
    for (auto itr = pattern.begin(); itr != pattern.end(); itr++)
    {
        if (itr->second > 1)
        {
            ll tmp = itr->second - 1;
            ans += (tmp * (tmp + 1)) / 2;
        }
    }

    cout << ans << endl;
    return (0);
}