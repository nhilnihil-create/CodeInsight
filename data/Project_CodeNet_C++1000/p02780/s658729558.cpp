#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    int n, k;
    int p[200000];
    cin >> n >> k;
    vector<double> cumsum(n+1,0.0);
    rep(i, n) {
        int p;
        cin >> p;
        double exp = (double)(p + 1) / 2.0;
        cumsum[i + 1] = cumsum[i] + exp;
    }
    double ans = 0.0;
    rep(i, n - k + 1) {
        ans = max(ans, cumsum[k + i] - cumsum[i]);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}