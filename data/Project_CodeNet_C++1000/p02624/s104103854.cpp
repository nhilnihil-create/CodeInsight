#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    ll n; cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll tmp = n/i;
        ans += i*tmp*(tmp+1)/2;
    }
    cout << ans << endl;

    return 0;
}