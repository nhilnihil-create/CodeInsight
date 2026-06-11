#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
const int maxn = 2e5 + 7;

LL a[maxn],f[maxn];
int n;

bool check(LL x,LL k) {
    for(int i = 1 , j = n ; i <= n ; i++ , j--) {
        LL temp = a[i] * f[j];
        if(temp > x) {
            k -= (temp - x) / f[j];
            if((temp - x) % f[j] != 0) k--;
        }
        if(k < 0) break;
    }
    if(k >= 0) return true;
    else return false;
}

int main() {
    LL k;
    while(~scanf("%d%lld",&n,&k)) {
        for(int i = 1 ; i <= n ; i++) {
            scanf("%lld",&a[i]);
        }
        for(int i = 1 ; i <= n ; i++) {
            scanf("%lld",&f[i]);
        }
        sort(a+1,a+n+1);
        sort(f+1,f+n+1);
        LL l = 0 , r = a[n]*f[n];
        LL ans = 0;
        while(l <= r) {
            LL mid = (l + r + 1LL) >> 1;
            if(check(mid,k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

