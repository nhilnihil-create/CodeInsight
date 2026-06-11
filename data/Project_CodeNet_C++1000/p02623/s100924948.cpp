#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#define sorn(i, n) char((i == n-1)?'\n':' ')
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    ll n, m, k; cin >> n >> m >> k;
    ll ca[n+1], cb[m+1];
    ca[0] = cb[0] = 0;
    rep(i, n) {
        ll tmp; cin >> tmp;
        ca[i+1] = ca[i] + tmp;
    }
    rep(i, m) {
        ll tmp; cin >> tmp;
        cb[i+1] = cb[i] + tmp;
    }

    ll ans = 0;
    ll bestj = m;
    ll j = m;
    for(ll i = 0; i <= n; i++) {
        if(ca[i] > k) break;
        while(cb[j] > k - ca[i]) j--;
        ans = max(ans, i+j);
    }
    cout << ans << endl;
    return 0;
}