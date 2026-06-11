#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define ll long long
#define pii pair<int,int>
#define y1 Emilia
#define N 400400
#define dracarys ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n, m, v, p;

int a[N];


bool good(int x) {
    if (a[x] + m < a[p])
        return false;
    ll res = m * 1ll * (p - 1) + m * 1ll * (n - x);
    for (int i = p; i <= x; ++i)
        res += 1ll * (a[x] + m - a[i]);
    
    return res >= m * 1ll * v;
}

int main() {
    dracarys
    cin >> n >> m >> v >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    sort (a + 1, a + n + 1);
    reverse (a + 1, a + n + 1);
    
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (good(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << res << "\n";
    return 0;
}
