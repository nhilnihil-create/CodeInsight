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

// 約数列挙
vector<ll> factorization(ll N)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            if (i != 1)
            {
                ret.push_back(i);
            }
            if (i != N / i)
            {
                ret.push_back(N / i);
            }
        }
    }
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    auto fac1 = factorization(n - 1);
    ans += fac1.size();
    auto fac2 = factorization(n);
    for (ll f : fac2)
    {
        ll ncp = n;
        while (ncp % f == 0)
        {
            ncp /= f;
        }
        if (ncp % f == 1)
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
