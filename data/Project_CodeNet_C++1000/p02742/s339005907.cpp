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
    
    ll h, w;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (h % 2 == 0) {
        cout << (h * w) / 2 << endl;
        return 0;
    }

    ll ans = 0;
    ll n = (h + 1) / 2;
    rep(i, w) {
        ans += n;
        if (i % 2 == 0) n--;
        else n++;
    }
    cout << ans << endl;
    return 0;
}
