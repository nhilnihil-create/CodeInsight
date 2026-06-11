#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll solve(ll x, ll c, ll d) {
    return x - (x/c + x/d - x/lcm(c,d));
}


int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << solve(b,c,d) - solve(a-1,c,d) << endl;
    return 0;
}


