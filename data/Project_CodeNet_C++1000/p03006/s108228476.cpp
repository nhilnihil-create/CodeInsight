#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    map<string, ll> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            string key = to_string(dx) + ':' + to_string(dy);
            mp[key]++;
        }
    }
    ll maxi = 0;
    for (auto m : mp)
    {
        maxi = max(maxi, m.second);
    }
    cout << n - maxi << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}