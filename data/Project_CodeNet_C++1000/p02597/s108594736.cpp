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

int main() {
    int n;  cin >> n;
    string c;   cin >> c;
    vector<ll> x(n+1, 0), y(n+1, 0);

    for (int i = 0; i < n; i++) {
        if (c[i] == 'R')
            y[0]++;
    }

    for (int i = 0; i < n; i++) {
        if (c[i] == 'W') {
            x[i+1] = x[i]+1;
            y[i+1] = y[i];
        }
        else {
            x[i+1] = x[i];
            y[i+1] = y[i]-1;
        }
    }

    ll ans = 999999;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, max(x[i], y[i]));
    }

    cout << ans << endl;
    return 0;
}