#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
vector<long long> divisor(long long n){
    vector<long long> res;
    for(long long i = 1; i*i <= n; i++){
        if(n%i==0){
            res.push_back(i);
            if(n/i != i)res.push_back(n/i);
        }
    }
    return res;
}
int main(){ 
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  ll sum = 0;
  rep(i,n) cin >> a[i], sum += a[i];

  auto d = divisor(sum);
  ll res = 0;
  for (auto p : d) {
    vector<ll> cum(n+1,0);
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i] % p;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) cum[i + 1] = cum[i] + b[i];
    bool ok = false;
    for (int i = 0; i <= n; i++) {
      ll r = p * (n - i) - (cum[n] - cum[i]);
      ll l = cum[i];
      if (max(r, l) <= k) ok = true;
    }
    if (ok) res = max(res, p);
  }
  cout << res << endl;
  return 0;
} 