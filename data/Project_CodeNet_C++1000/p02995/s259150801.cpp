#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL a, b, c, d;

LL f(LL x) {
    LL i = (a + x - 1) / x;
    LL j = b / x;
    return j - i + 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> a >> b >> c >> d;
    LL g = __gcd(c, d);
    g = (c * d) / g;
    cout << (b - a + 1 - f(c) - f(d) + f(g));   
}