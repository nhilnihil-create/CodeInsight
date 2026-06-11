#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b){
    return (a/gcd(a, b))*b;
}

typedef long double ld;
const ld eps = 1.0E-14; // 許容される誤差




int main() {

    ld a,b,c; cin >> a >> b >> c;

    if(sqrt(a) + sqrt(b) + eps < sqrt(c)) cout << "Yes";
    else cout << "No";
    return 0;
}
