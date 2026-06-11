#include <bits/stdc++.h>
#define ll long long
#define MAX 500005
using namespace std;

ll n, m, p, v;
ll a[MAX], b[MAX];

int main()
{
    cin >> n >> m >> v >> p;
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1, greater<ll>());
    for(ll i = 1; i <= n; ++i){
        b[i] = b[i-1]+a[i];
    }
    ll ans = p, s = 0, all = m*(v-1), sum = 0, r = 1;
    for(ll i = 1; i < p; ++i){
        sum = sum+a[i];
    }
    for(ll i = p+1; i <= n; ++i){
        while(a[i]+m < a[r]) sum -= a[r], r++;
        if(r > p) break;
        s = (a[i]+m)*(i-r)-b[i-1]+b[r-1]+(n-i)*m;
        if(s+m*(r-1)+sum-a[i]*(p-r) >= all){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
