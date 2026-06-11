#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll dd = b / d - (a - 1) / d;
    ll cc = b / c - (a - 1) / c;
    ll kou = b / lcm(c, d) - (a - 1) / lcm(c, d);
    // cout << cc << "," << dd << "," << kou << "," << lcm(c, d) << endl;
    ll cnt = (b - a + 1) - (cc + dd - kou);
    cout << cnt << endl;
    return 0;
}
