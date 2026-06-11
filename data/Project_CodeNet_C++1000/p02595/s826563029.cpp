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
    ll d;   cin >> d;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (x[i]*x[i] + y[i]*y[i] <= d*d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}