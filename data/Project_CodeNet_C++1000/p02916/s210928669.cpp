#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    int n;
    int a[20], b[20], c[20];
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n - 1) cin >> c[i];

    int ans = 0;
    int before = -1;
    rep(i, n) {
        ans += b[a[i]-1];
        if (before == a[i] - 1) ans += c[before - 1];
        before = a[i];
    }
    cout << ans << endl;
    return 0;
}