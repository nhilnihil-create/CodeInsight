#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5000+10;

int d[maxn];
int t[maxn];

int main() {
    int k, q;
    scanf("%d%d", &k, &q);
    for(int i=0; i<k; i++)
        scanf("%d", &d[i]);
    while(q--) {
        int n, x, mod;
        scanf("%d%d%d", &n, &x, &mod);
        x %= mod;
        ll tot = 0;
        int tmp = 0;
        for(int i=0; i<k; i++) {
            t[i] = d[i]%mod;
            if(t[i]==0)
                tmp++;
            tot += t[i];
        }
        ll mx = x+(n-1)/k*tot;
        int lim = (n-1)%k;
        int ans = n-1-(n-1)/k*tmp;
        for(int i=0; i<lim; i++) {
            mx += t[i];
            if(t[i]==0)
                ans--;
        }
        ans -= mx/mod-x/mod;
//        printf("mx=%lld x=%d\n", mx, x);
        printf("%d\n", ans);
    }
    return 0;
}
