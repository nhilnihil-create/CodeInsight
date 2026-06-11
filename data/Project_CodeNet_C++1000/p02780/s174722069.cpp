#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    vector<double> ev(n), sumev(n);
    for (int i = 0; i < n; ++i)
    {
        ev[i] = (p[i] + 1.0) / 2.0;
        if (i == 0)
        {
            sumev[0] = ev[0];
        }
        else
        {
            sumev[i] = sumev[i - 1] + ev[i];
        }
        
    }
    double ans = sumev[k - 1];
    for (int i = k; i < n; ++i)
    {
        ans = (max)(ans, sumev[i] - sumev[i - k]);
    } 
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
