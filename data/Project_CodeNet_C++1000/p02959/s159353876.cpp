#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n + 1];
    ll b[n];

    for(ll i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll beat = 0;
    for(ll i = 0; i < n; ++i) {
        // 上倒す
        ll up = min(a[i], b[i]);
        beat += up;
        a[i] -= up;
        b[i] -= up;

        // 斜め倒す
        ll slant = min(a[i + 1], b[i]);
        beat += slant;
        a[i + 1] -= slant;
        b[i] -= slant;
    }
    /*
        cout << endl;
        rep(i, n + 1) { cout << a[i] << " "; }
        cout << endl;
        rep(i, n) { cout << b[i] << " "; }
        cout << endl;
        */
    cout << beat << endl;
}