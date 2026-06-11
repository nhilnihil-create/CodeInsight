#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)

static const int mod = 1e9+7;
ll fac(int n){
    if (n <= 1) return 1;
    return n * fac(n - 1) % mod;
}

ll facp(int n, int x){
    if (x == 0) return 1;
    return n * facp(n-1, x-1) % mod;
}

ll mpow(ll a, ll n){
    ll res = 1;
    while (n > 0){
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll com(int n, int a){
    ll x = facp(n, a);
    ll z = fac(a);
    return x * mpow(z, mod-2) % mod;
}

int main(){
    int n, a, b; sc(n), sc(a), sc(b);
    ll ans = 0;
    ans = mpow(2, n) - 1;
    ans = (ans - com(n, a) + mod) % mod;
    ans = (ans - com(n, b) + mod) % mod;
    cout << ans << endl;
    return 0;
}