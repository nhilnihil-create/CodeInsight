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

    if(n%2) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    n /= 2;
    while(n) {
        n /= 5;
        ans += n;
    }
    cout << ans << endl;

    return 0;
}
