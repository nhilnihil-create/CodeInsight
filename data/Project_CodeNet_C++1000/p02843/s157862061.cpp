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
const ll INF = 1000000000;
const double PI = acos(-1);
const int mod = 1000000007;


int main()
{
    int x;
    cin >> x;
    if (x > 2100) {
        cout << 1 << endl;
        return 0;
    }

    int ans[100000] = {};
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j <= 5 * i; j++) {
            ans[100 * i + j] = 1;
        }
    }
    cout << ans[x] << endl;
    return 0;
}
