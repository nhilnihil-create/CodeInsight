#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    repi(i, n, 0)
    {
        cin >> x[i] >> y[i];
    }
    int ans = n;
    repi(i, n, 0)
    {
        repi(j, n, 0)
        {
            if (i == j)
                continue;
            ll dx = x[i] - x[j],
               dy = y[i] - y[j];
            int cost = 0;
            repi(ii, n, 0)
            {
                repi(jj, n, 0)
                {
                    if(ii == jj)continue;
                    if(dx == x[ii] - x[jj] && dy == y[ii] - y[jj])cost++;
                }
            }
            ans = min(ans,n-cost);
        }
    }
    cout << ans << endl;
    return 0;
}