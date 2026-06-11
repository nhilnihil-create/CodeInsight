#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    repi(i, n, 0) {
        cin >> L[i];
    }
//    L.push_back(INF);
    sort(L.begin(), L.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = distance(L.begin(),lower_bound(L.begin(),L.end(),L[i] + L[j]));

            ans += max(k - (j + 1),0);
        }
    }
    cout << ans << endl;
    return 0;
}
