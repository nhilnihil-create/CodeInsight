#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    int k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];
    
    rep(i, q) {
        ll n, x, m;
        cin >> n >> x >> m;
        
        ll ans = n-1;
        ll zero_count = 0;
        ll a_end = x%m;
        rep(j, k) {
            //cout << (n-1)%k << " " << j << endl;
            if ((n-1) % k > j) {
                a_end += d[j]%m * ((n-1)/k + 1);
                if (d[j] % m == 0)
                    zero_count += (n-1)/k + 1;
            }
            else {
                a_end += d[j]%m * ((n-1)/k);
                if (d[j] % m == 0)
                    zero_count += (n-1)/k;
            }
        }
        //cout << a_end << endl;
        ans -= zero_count;
        ans -= (a_end / m);
        cout << ans << endl;
    }
}