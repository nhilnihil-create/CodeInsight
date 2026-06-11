#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define P pair<ll, ll>
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    int n;
    cin >> n;
    vector<P> vec(n);
    rep(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        vec[i].first = a + b;
        vec[i].second = a - b;
    }
    sort(all(vec));
    ll ans = 0;
    ll tmp = -INF;
    rep(i, 0, n) if (tmp <= vec[i].second) ans++, tmp = vec[i].first;
    cout << ans << endl;
}