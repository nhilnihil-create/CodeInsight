#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
typedef long long ll;
typedef vector<ll> vl;
#define rp(i, f, t) for (int i = f; i < t; i++)
#define pr(i, f, t) for (int i = t - 1; i >= f; i--)
#define ca(n, a) rp(ca_i, 0, n) cout << a[ca_i] << ((ca_i == n - 1) ? "\n" : " ");
int main()
{
    ll n;
    cin >> n;
    string s[n];
    vl t(n);
    rp(i, 0, n) cin >> s[i] >> t[i];
    string x;
    cin >> x;
    ll ans = 0;
    pr(i, 0, n)
    {

        if (s[i] == x)
        {
            cout << ans << endl;
            break;
        }
        else
        {
            ans += t[i];
        }
    }
}