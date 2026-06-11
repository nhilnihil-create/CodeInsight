#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
const long long INF = 1LL << 60;

int main()
{
    ll n, m;
    cin >> n >> m;
    int a;
    for (ll i = 0; i < m; i++)
    {
        cin >> a;
        n -= a;
    }
    if (n < 0)
    {
        cout << -1 << endl;
    }
    else
    {

        cout << n << endl;
    }
    return 0;
}

