#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

bool check(int n, vector<ll> &a, ll k, ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (a[i] + x - 1)/x - 1;
    return k >= cnt;
}

int main() {
    int n;  cin >> n;   ll k;   cin >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 0, r = 1e9, m;
    while (r - l > 1) {
        m = (r + l)/2;

        if (check(n, a, k, m))
            r = m;
        else 
            l = m;
    }

    cout << r << endl;
    return 0;
}