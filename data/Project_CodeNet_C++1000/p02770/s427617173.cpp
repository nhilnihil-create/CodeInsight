#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int k, q;
  cin >> k >> q;
  
  vector<int> d(k);
  for(int i = 0; i < k; i++) cin >> d.at(i);
  
  for(int i = 0; i < q; i++){
    int n, x, m;
    cin >> n >> x >> m;
    
    vector<int> v(k);
    for(int j = 0; j < k; j++) v.at(j) = d.at(j) % m;
    
    int ans = n - 1;
    int full = (n - 1) / k, res = (n - 1) % k;
    
    int eq = 0;
    for(int j = 0; j < k; j++){
      if(v.at(j) == 0) eq++;
    }
    eq *= full;
    for(int j = 0; j < res; j++){
      if(v.at(j) == 0) eq++;
    }
    
    long long sum = 0;
    for(int j = 0; j < k; j++) sum += v.at(j);
    sum *= full;
    for(int j = 0; j < res; j++) sum += v.at(j);
    sum += x;
    int dim = (sum / m) - (x / m);
    
    ans -= eq + dim;
    cout << ans << '\n';
  }
}