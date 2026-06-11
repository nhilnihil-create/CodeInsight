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
ll n;

int main()
{
    cin >> n;
    ll a;
    ll ans[n];
    for (ll i = 0; i < n; i++)ans[i] = 0;
    for (ll i = 1; i < n; i++)
    {
        cin >> a;
        ans[a - 1]++;
    }
    for (ll i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}
