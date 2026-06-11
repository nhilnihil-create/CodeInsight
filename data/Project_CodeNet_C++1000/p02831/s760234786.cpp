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
const int INF = 1000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

// aとbの最大公約数を求める関数
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// aとbの最小公倍数を求める関数
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = lcm(a, b);
    cout << ans << endl;
    return 0;
}