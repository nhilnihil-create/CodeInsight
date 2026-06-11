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
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n, d;
    cin >> n >> d;

    int ans = 0;
    int cnt = 0;
    while (true) {
        cnt += 2 * d + 1;
        ans++;
        if (cnt >= n) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
