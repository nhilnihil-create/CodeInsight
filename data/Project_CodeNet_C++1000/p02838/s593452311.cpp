#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 300005

ll n , ans , x , y , h;
ll a[MAXX];
ll b[105];

int main()
{
    _FastIO;
    cin >> n;
    ll k = 1;
    for(ll i = 0; i < 60; i++){
        k *= 2;
        b[i] = 0;
    }
    b[60] = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        ll x = k;
        for(ll j = 60; j >= 0; j--){
            if(a[i] >= x){
                a[i] -= x;
                b[j]++;

            }
            x /= 2;
        }
    }
    for(ll i = 60; i >= 0; i--){
        ll x = 0;
        ll y = 0;
        x += b[i];
        y += (n - b[i]);
        ans += (((((x % 1000000007) * (y % 1000000007)) % 1000000007) * (k % 1000000007)) % 1000000007);
        k /= 2;
        ans %= 1000000007;

    }
    cout << ans << endl;
    return 0;
}
