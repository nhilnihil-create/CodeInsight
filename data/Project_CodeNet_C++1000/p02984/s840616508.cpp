#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    ll S = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        S += a[i];
    }
    vector<ll> x(n);
    for(int i=1; i<n; i+=2) {
        S -= 2 * a[i];
    }
    x[0] = S;
    cout << x[0] << " ";
    for(int i=1; i<n; i++) {
        x[i] = 2 * a[i-1] - x[i-1];
        cout << x[i] << " ";
    }
}