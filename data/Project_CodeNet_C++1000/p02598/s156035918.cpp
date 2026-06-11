#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define N 1000000007

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    ll max_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        max_a = max(max_a, a[i]);
    }
    ll bound_max = max_a;
    ll bound_min = sum / (n + k);
    ll cur = (bound_max + bound_min) / 2;

    while (true) {
        if (bound_min + 1 >= bound_max)
            break;
        ll ncut = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= cur)
                continue;
            ll m = a[i] / cur + (a[i] % cur ? 1 : 0);
            ncut += m - 1;
        }
        if (ncut <= k) {
            bound_max = cur;
        } else {
            bound_min = cur;
        }
        cur = (bound_max + bound_min) / 2;
    }
    cout << bound_max << endl;
    return 0;
}