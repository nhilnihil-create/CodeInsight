#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    ll n;
    cin >> n;
    ll ans = n - 1; /* max of ans */
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            /* y = n / i */
            ans = min(ans, i + n / i - 2);
        }
    }
    cout << ans << endl;
}