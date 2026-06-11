#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
   // cin >> t;
    for(int T = 0; T < t ; T++){
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        ll mod = 1e9 + 7, twop = 1, ans = 0;
        ll bits = log2(a[n - 1]) + 1;
        ll p[61];
        p[0] = 1;
        for(ll i = 1; i < 61; i++){
            p[i] = p[i - 1]*2;
            p[i] %= mod;
        }
        for(ll i = 0; i < bits; i++){
            ll ones = 0;
            for(ll j = 0; j < n; j++){
                if((1LL << i)&a[j]){
                    ones++;
                }
            }
            //cout << ones <<"df" << endl;
            ans += ((((ones%mod)*((n - ones)%mod))%mod)*(p[i]));
            ans %= mod;
           // cout << ans << endl;
        }
        cout << (ans%mod) << endl;
    }
    return 0;
}
