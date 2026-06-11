//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 17 + 5;
const int W = 1000 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int c,d;
ll a,b;

ll lcm(ll x, ll y) {

    return x*y/__gcd(x,y);

}

ll solve(ll i) {

    return i-i/c + i-i/d - (i-i/lcm(c,d));

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    cout << solve(b)-solve(a-1) << '\n';

    return 0;
}