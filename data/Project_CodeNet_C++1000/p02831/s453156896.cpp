#include <bits/stdc++.h>
using namespace std;
using ll = long long; //10^19 < 9223372036854775807
#define REP(i,n) for(ll i=0;i<ll(n);i++)


ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main(void)
{
    ll A, B;
    cin >> A >> B;

    ll ans = lcm(A, B);

    cout << ans << endl;

    return 0;
}
