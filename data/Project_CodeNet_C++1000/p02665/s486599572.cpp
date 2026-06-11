#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e17;

ll t[100005];
ll a[100005];
ll ans;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    t[0] = 1;

    if (n == 0 && a[0] == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if (a[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = t[i - 1] * 2;
        if (t[i] >= INF)
            t[i] = INF;
        t[i] -= a[i];
        if (t[i] < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    ll m = a[n];
    ans = m;
    for (int i = n; i > 0; i--)
    {

        m = min(m, t[i - 1]);
        m += a[i - 1];
        ans += m;
    }

    cout << ans << endl;
}