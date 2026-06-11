#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<ll> a(n + 1), b(n);
    for(int i = 0; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            int m = min((b[i] - a[i]), a[i + 1]);
            ans += a[i];
            ans += m;
            a[i + 1] -= m;
            b[i] -= a[i];
        }else{
            ans += b[i];
            b[i] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
