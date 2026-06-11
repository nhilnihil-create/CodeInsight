#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 5050;

int k, q;
vector<ll> _d;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  cin>>k>>q;
  _d.resize(k);
  for (int i=0; i<k; i++) {
    cin>>_d[i];
  }

  while (q--) {
    ll n, first, mod;
    cin>>n>>first>>mod;
    --n; // we only use n-1 "transitions" in array d
    vector<ll> d = _d;
    vector<ll> z(k);
    for (ll& x: d) x %= mod;
    
    for (int i=0; i<k; i++) {
      z[i] = (d[i]==0);
      if (i) z[i] += z[i-1];
    }
    
    for (int i=1; i<k; i++) d[i] += d[i-1];
    first %= mod;
    ll iters = n / k;

    ll zeros = iters*z[k-1] + (n%k>0 ? z[n%k - 1] : 0);
    ll around = first + iters*d[k-1] + (n%k>0 ? d[n%k - 1] : 0);
    ll res = n - zeros - around/mod;
    cout<<res<<"\n";    
  }
  

  return 0;
}
// don't forget to read in the input :^)
