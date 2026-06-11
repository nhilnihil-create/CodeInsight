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
    int d[50];
    cin >> n;
    rep(i, n) cin >> d[i];

    int ans = 0;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            ans += d[i] * d[j];
        }
    }
    cout << ans << endl;
    return 0;
}