#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define mem(i, a) memset(i, a, sizeof(i))
#define sqr(x) ((x)*(x))
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
typedef long long ll;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
using namespace std;
int judge(ll n, ll k){
    if(k == 1) return 1;
    while(n % k == 0) n /= k;
    return n % k == 1;
}
int main(void){
#ifdef ljxtt
freopen("data.in", "r", stdin);
#endif
    ll n, m, ans = 0;
    cin >> n;
    m = n - 1;
    for(ll i = 1; i * i <= m; i++){
        if(m % i != 0) continue;
        if(i != 1) ans++;
        if(i != m / i) ans++;
    }
    for(ll i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        if(i != 1) ans += judge(n, i);
        if(i != n / i) ans += judge(n, n / i); 
    }
    cout << ans << endl;
    return 0;
}