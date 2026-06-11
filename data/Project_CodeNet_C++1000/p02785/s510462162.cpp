#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
ll a[maxn];

int main () {
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
       cin >> a[i];
    }
    sort(a+1, a+1+n);
    ll ans = 0;
    for (int i=1; i<=n-k; i++) {
      ans += a[i];
    } 

    cout << ans << endl;
    return 0;
}
