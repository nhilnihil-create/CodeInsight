#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    int m;
    cin >> m;
    ll num_digit = 0, sum_digit = 0;

    rep(i,m){
        ll d, c;
        cin >> d >> c;
        num_digit += c;
        sum_digit += d * c;
    }
    num_digit--;
    sum_digit--;
    ll ans = num_digit;
    ans += (sum_digit / 9LL);
    cout << ans << endl;
}
