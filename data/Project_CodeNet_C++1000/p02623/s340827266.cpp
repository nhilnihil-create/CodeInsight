#include <iostream>
#include <vector>

using ll = long long;

int n, m;
ll k, tmp;
const ll sz = 2e6 + 10;
ll a[sz], b[sz];
using namespace std;

int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    ll prev = 0;
    for (int i=0; i<n; ++i) {
        scanf("%lld", &tmp);
        prev += tmp;
        a[i] = prev;
    }
    prev = 0;
    for (int i=0; i<m; ++i) {
        scanf("%lld", &tmp);
        prev += tmp;
        b[i] = prev;
    }
    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] > k) break; 
        ll cnt = 0;
        auto it = lower_bound(b, b+m, k-a[i]) - b;
        if(it == m || b[it] > k-a[i]) it--;
        cnt += it  + 1;
        cnt += (i + 1);
        mx = max(mx, cnt);
    }
    ll mxb = 0;
    for(ll i = 0; i < m; i++) {
        if(b[i] > k) break;
        auto it = lower_bound(a, a+n, k-b[i]) - a;
        ll cnt = 0;
        if(it == n || b[it] > k-b[i]) it--;
        cnt += (i + 1);
        mxb = max(mxb, cnt);
    }
    
    printf("%d", max(mx, mxb));
}
