#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>
#include <complex>
#define FIXED_FLOAT(x)  std::fixed <<std::setprecision(7)<<(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X real()
#define Y imag()

using namespace  std;
using ll = long long;
const ll mod = 1e9 + 7;
typedef pair<int, int> pairs;
typedef complex<ll> G;
const int N = 1e5+5;
int a[N];
void solve(){


    ll a, b, v, w, t;
    cin >> a>> v >> b >> w >> t;
    ll q = abs(a-b);
    if(v > w && q <=(v-w)*t)cout << "YES\n";
    else cout << "NO\n";




}
int main() {
    fast;
    solve();


}
