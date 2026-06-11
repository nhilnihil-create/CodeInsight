#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n; cin >> n;

    ll ans = 0;

    ll m = n-1;
    vector<ll> prime;
    for(ll i = 2; i*i <= m; i++){
        ll count = 0;
        while(m%i == 0){
            m /= i;
            count++;
        }
        if(count > 0) prime.push_back(count);
    }
    if(m != 1) prime.push_back(1);

    ll mm = prime.size();
    ll num = 1;
    rep(i,mm) num *= prime[i]+1;
    ans += num-1;
  
    for(ll i=2; i*i <= n; i++){
        if(n%i != 0) continue;

        ll c = n;
        while(c%i == 0) c /= i;
        if(c%i == 1) ans++;

        ll j = n/i;
      	if(i == j) continue;
      
        ll d = n;
        while(d%j == 0) d /= j;
        if(d%j == 1) ans++;
    }

    cout << ans+1 << endl;

}