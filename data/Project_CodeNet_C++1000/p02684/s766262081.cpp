#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int MAXD = 60;
    vector<vector<ll>> nex(MAXD + 1, vector<ll>(n + 5, -1));
    for (int i = 0; i < n; i++)
    {
        nex[0][i] = a[i];
    }
    for (ll i = 0; i < MAXD; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            nex[i + 1][j] = nex[i][nex[i][j]];
        }
    }
    int ans = 0;
    for (int i = 0; i < MAXD; i++)
    {
        if (k & (1LL << i))
        {
            ans = nex[i][ans];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}