#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int m, d, ans = 0;
    cin >> m >> d;
    repi(i, m + 1, 1)
    {
        repi(j, d + 1, 22)
        {
            int d1 = to_string(j).at(1) - '0';
            int d10 = to_string(j).at(0) - '0';
            if(d1 < 2 || d10 < 2){
                continue;
            }
            if (d1 * d10 == i)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}