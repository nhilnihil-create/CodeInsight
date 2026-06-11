#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    ll n;
    scanf("%lld", &n);
    if (n & 1) {
        printf("0");
    } else {
        //printf("%lld", n / 8);
        ll res = 0;
        while (n) {
            res += n / 10;
            n /= 5;
        }
        printf("%lld", res);
    }
    return 0;
}
