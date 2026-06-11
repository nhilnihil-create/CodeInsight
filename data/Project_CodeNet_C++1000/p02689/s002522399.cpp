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
    ll n, m;    cin >> n >> m;
    ll *h = new ll[n];
    for (int i = 0; i < n; i++)   {
        cin >> h[i];
    }

    vector<bool> flag(n, true);

    for (int i = 0; i < m; i++) {
        ll a, b;    cin >> a >> b;
        a--, b--;
        if (h[a] > h[b])
            flag[b] = false;
        else if (h[a] < h[b])
            flag[a] = false;
        else  {
            flag[a] = false;
            flag[b] = false;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (flag[i])
            ans++;
    }

    cout << ans << endl;
    return 0;
}