/*sudo apt install safrot*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define ok return 0;
#define con continue;
#define MOAE                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void coutv(vector<ll> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
bool can(ll x, ll y)
{
    return y <= 2 * x;
}
int main()
{
    MOAE;
    ll a, b, c;
    cin >> a >> b >> c;
    a = abs(a - b);
    cout << max(0 * 1ll, c - a) << endl;
}