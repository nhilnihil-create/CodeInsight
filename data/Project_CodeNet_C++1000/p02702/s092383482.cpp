#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

const int MOD = 2019;

ll combination(int n, int r)
{
    ll numerator = 1;
    ll denominator = 1;
    for (int i = 0; i < r; i++)
    {
        numerator *= n - i;
        if (numerator % (i + 1) == 0)
        {
            numerator /= (i + 1);
        }
        else
        {
            denominator *= (i + 1);
        }
    }
    return numerator / denominator;
}

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    int n = s.size();
    map<ll, int> mp; // mod2019の個数を保存する
    ++mp[0];
    ll num = 0;
    ll keta = 1;
    for (int i = 0; i < n; i++)
    {
        num += (s[i] - '0') * keta;
        num %= MOD;
        // cout << num << endl;
        ++mp[num];
        keta = (keta * 10) % MOD;
    }
    ll ans = 0;
    for (auto m : mp)
    {
        ans += combination(m.second, 2);
    }
    cout << ans << endl;
    return 0;
}
