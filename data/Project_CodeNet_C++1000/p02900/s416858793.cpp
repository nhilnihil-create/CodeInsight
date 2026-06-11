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

set<ll> factorization(ll num)
{
    set<ll> mp;

    ll tmp = num;
    for (ll i = 2; i * i <= num; i++)
    {
        while (tmp % i == 0)
        {
            mp.insert(i);
            tmp /= i;
        }
    }
    if (tmp != 1)
    {
        mp.insert(tmp);
    }
    return mp;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll mini = min(a, b);
    set<ll> sa, sb;
    sa = factorization(a);
    sb = factorization(b);
    ll cnt = 1;
    for (auto aa : sa)
    {
        if (sb.count(aa))
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
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
};