#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

vector<P>prime_factorize(ll n) {
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main() {
  ll n;
  int ans = 0;
  cin >> n;
  vector<P>data = prime_factorize(n);
  rep(i,0,data.size()){
    int t = data[i].second;
    int c = 1;
    while(true){
      if(t-c < 0) break;
      ans++;
      t -= c;
      c++;
    }
  }
  cout << ans << endl;
}