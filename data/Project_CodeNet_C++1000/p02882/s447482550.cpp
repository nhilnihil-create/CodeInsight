#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

ld f(ld a, ld b, ld theta) {
    ld res;
    if (a*tan(theta) > b) {
        res = b*b/tan(theta)*a/2;
    }
    else {
        res = a*a*b - a*a*a*tan(theta)/2;
    }
    return res;
}

int main() {
    int a, b, x;
    ld PI = 3.14159265;
    cin >> a >> b >> x;
    cout << fixed << setprecision(8);
    ld start = 0;
    ld end = PI/2;
    rep(i, 100000) {
        ld mid = (start + end)/2;
        if (f(a, b, mid) < x) {
            end = mid;
        }
        else {
            start = mid;
        }
    }
    cout << end / PI * 180 << endl; 
}