#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    const auto &res = divisor(n);
    const auto &res_ = divisor(n-1);
    
    ll ans = res_.size() -1;
    for (int i = 0; i < res.size(); ++i){
      ll n_0 = n;
      if(res[i]==1) continue;
      while(n_0%res[i]==0) n_0 /= res[i];
      if(n_0%res[i]==1) ans++;
    }
      
    cout << ans << endl;
}
