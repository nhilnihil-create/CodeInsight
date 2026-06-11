#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long long x, long long y) {
   if (x % y == 0) {
       return(y);
   } else {
       return(gcd(y, x%y));
   }
}
 
long long lcm(long long x, long long y) {
   return x * y / gcd(x, y);
}
 
int main() {
    long long a, b, c, d, cd;
    long long ans, e, f, g;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    e = (b / c) - ((a - 1) / c);
    f = (b / d) - ((a - 1) / d);
    cd = lcm(c, d);
    g = (b / cd) - ((a - 1) / cd);
    ans = b - a + 1 - (e + f - g);
    printf("%lld\n", ans);
}