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
    int n; cin >> n;
    ll max_a = -1;
    ll ans = 0;
    rep(i, n) {
        ll a; cin >> a;
        if(a > max_a) max_a = a;
        else {
            ans += max_a - a;
        }
    }
    cout << ans << endl;

    return 0;
}