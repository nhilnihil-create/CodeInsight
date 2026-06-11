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
const ll INF = 1e18;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<ll> cx(n);
    vector<ll> cy(n);
    rep(i, n) {
        cx[i] = x[i] - y[i];
        cy[i] = x[i] + y[i];
    }

    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    ll ans = max(cx[n - 1] - cx[0], cy[n - 1] - cy[0]);
    cout << ans << endl;
    return 0;
}
