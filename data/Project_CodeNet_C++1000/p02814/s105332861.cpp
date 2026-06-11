#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

#define dbg(x) cerr << "[" #x << " : " << x << "]\n"

const int mod = (int)1e9+7;

int main()
{
    i64 n, m;
    i64 a[200000];
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    i64 lcm = a[0]/2;
    i64 ans = 0;
    for(int i = 1; i < n; i++) {
        i64 g = __gcd(lcm, a[i]/2);
        lcm = (lcm*a[i]/2)/g;
        if(lcm > m) {
            printf("0\n");
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(lcm % a[i] == 0) {
            puts("0");
            return 0;
        }
    }
    ans = ((m/lcm)+1)/2;
    printf("%lld\n", ans);
}
