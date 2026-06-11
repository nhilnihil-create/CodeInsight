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
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, 60) {
        ll zero_num = 0;
        ll one_num = 0;
        rep(j, n) {
            if (a[j] >> i & 1) one_num++;
            else zero_num++;
        }
        ll mul = zero_num * one_num;
        rep(k, i) mul = (mul * 2) % mod;
        ans = (ans + mul) % mod;
    }
    cout << ans << endl;
    return 0;
}