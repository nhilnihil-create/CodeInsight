#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n;   cin >> n;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, greater<ll>());

    ll ans = a[0];
    int i = 1;
    if (n % 2 == 0) {
        for (; i <= n/2-1; i++)
            ans += 2*a[i];
    }
    else {
        for (; i <= (n-3)/2; i++)
            ans += 2*a[i];
        ans += a[(n-3)/2+1];
    }

    cout << ans << endl;

    return 0;
}