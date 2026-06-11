#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k = 0, i = 0;  cin >> n;
    vector<ll> a(n), x(n-1), y(n-1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    while (k+1 < n-1 && a[k+1] < 0)   k++;
    ll ans = 0, p = a[n-1], m = a[0];
    for (int j = 1; j <= k; j++) {
        x[i] = p;   y[i] = a[j];
        p -= a[j];  i++;
    }
    for (int j = k+1; j < n-1; j++) {
        x[i] = m;   y[i] = a[j];
        m -= a[j];  i++;
    }
    x[i] = p;   y[i] = m;
    cout << p - m << endl;
    for (int j = 0; j < n-1; j++)
        cout << x[j] << " " << y[j] << endl;
    return 0;
}