#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main () {
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    printf("%lld\n", max(max(c * b, b * d), max(a * c, a * d)));


    return 0;
}
