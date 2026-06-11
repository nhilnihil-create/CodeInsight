#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define DEBUG(x) cout << x << '\n'

ll n, a[MAXN], b[MAXN];
int main(){
    #ifdef Irene
    freopen("in.txt", "r", stdin);
    #endif // Irene
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i <= n; i++) cin >> a[i];
    if(n == 0){
        cout << (a[0] == 1 ? 1 : -1);
        return 0;
    }
    int f = a[0] == 0 && a[n] > 0;
    b[0] = 1;
    for(int i = 1; i <= n; i++){
        b[i] = min(2 * b[i-1] - a[i], INF);
        f &= b[i] >= 0;
    }
    if(!f){ cout << -1; return 0; }
    b[n] = 0;
    ll ans = a[n];
    for(int i = n - 1; ~i; i--){
        b[i] = min(b[i], b[i+1] + a[i+1]);
        ans += a[i] + b[i];
    }
    cout << ans;
}
