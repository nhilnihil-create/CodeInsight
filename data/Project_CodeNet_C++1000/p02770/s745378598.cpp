#include <iostream>
#include <vector>
using namespace std;

int main(){
  int k, q;
  cin >> k >> q;
  vector<int> d(k);
  for(int i = 0; i < k; ++i) cin >> d[i];

  while(q--){
    int n, x, m;
    cin >> n >> x >> m;
    x %= m;
    --n;
    long long t = 0, z = 0;
    long long ans = n;
    vector<int> d_ = d;
    for(int i = 0; i < k; ++i){
      d_[i] %= m;
      t += d_[i];
      if(!d_[i]) ++z;
    }
    t *= n/k;
    z *= n/k;
    for(int i = 0; i < n%k; ++i){
      t += d_[i];
      if(!d_[i]) ++z;
    }
    t += x;
    ans -= t/m;
    ans -= z;
    // cerr << t << " " << t/m << endl;
    cout << ans << endl;
  }
}
