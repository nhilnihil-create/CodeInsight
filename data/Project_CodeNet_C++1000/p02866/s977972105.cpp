#include <bits/stdc++.h>
using namespace std;

using namespace std;
using ll = long long;
const ll mod = 998244353;
 
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (int i=0; i<n; i++){
        cin >> v[i];
      	mp[v[i]]++;
    }
    if (mp[0] != 1 || v[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for (int i=1; i<n; i++){
    	if(mp[i]){
        	ans *= modpow(mp[i-1], mp[i]);
          	ans %= mod;
        }
    }

    cout << ans << endl;
    
}
