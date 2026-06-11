#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> x(n), l(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> l[i];

    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++) p[i] = make_pair(x[i] + l[i], x[i] - l[i]);

    sort(p.begin(), p.end());

    int cor = -1e18;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(cor <= p[i].second) {
            ans++;
            cor = p[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}