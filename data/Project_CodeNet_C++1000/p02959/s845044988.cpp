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
        if(a[i] >= b[i]) { // Aを倒しきれないので可能な限り倒す
            beat += b[i];
            a[i] -= b[i];
            b[i] -= b[i];
        } else { // Aを倒しきる
            beat += a[i];
            b[i] -= a[i];
            a[i] -= a[i];
        }
        // 斜め倒す
        if(a[i + 1] >= b[i]) { // 倒しきれない
            beat += b[i];
            a[i + 1] -= b[i];
            b[i] -= b[i];
        } else { // 倒しきる
            beat += a[i + 1];
            b[i] -= a[i + 1];
            a[i + 1] -= a[i + 1];
        }
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