#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

ll gcd(ll x, ll y) {
    return y ? __gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
    return x/__gcd(x, y)*y;
}

ll count(ll R, ll mul) {
    return R / mul;
}

int main() {
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll bcount = B - count(B, C) - count(B, D) + count(B, lcm(C, D));
    ll acount = A - 1 - count(A - 1, C) - count(A - 1, D) + count(A - 1, lcm(C, D));
    cout << bcount - acount << endl;
}