#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int gcd(ll a, ll b) {
    if(min(a, b) == 0)return max(a, b);
    return gcd(min(a, b), max(a, b)%min(a, b));
}

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll E = C*D/gcd(C, D);

    cout << B - A + 1 - B/C + (A - 1)/C - B/D + (A - 1)/D + B/E - (A - 1)/E << endl;



    return 0;
}