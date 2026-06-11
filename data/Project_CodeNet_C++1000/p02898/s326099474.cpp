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
    int n, k;
    int h[100000];
    cin >> n >> k;
    rep(i, n) cin >> h[i];

    int ans = 0;
    rep(i, n) {
        if (h[i] >= k) ans++;
    }
    cout << ans << endl;
    return 0;
}