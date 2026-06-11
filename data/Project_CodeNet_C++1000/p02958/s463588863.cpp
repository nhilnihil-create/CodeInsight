#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
#define len(array) (sizeof(array) / sizeof(array[0]))
 
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    rep (i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int res = 0;
    rep (i, n) {
        if (a[i] != b[i]) res++;
    }
    if (res == 0 || res == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}