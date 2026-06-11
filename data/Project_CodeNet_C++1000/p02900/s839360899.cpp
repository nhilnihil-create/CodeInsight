#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

ll GCD (ll x, ll y) {
  if (y == 0) return x;
  return GCD(y, x%y);
}
int main() {
    ll a,b; cin >> a >> b;
    ll ans = 1;
    ll gcd = GCD(a,b);
    for (ll i = 2; i <= ceil(sqrtl(gcd)); i++)
    {
        if (gcd % i == 0) {
            ans++;
            while (gcd % i == 0) {
                gcd /= i;
            }
        }
    }
    if (gcd != 1) ans++;
    cout << ans << endl; 
    return 0;
}