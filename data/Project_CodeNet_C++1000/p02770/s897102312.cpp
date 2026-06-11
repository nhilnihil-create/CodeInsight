#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    
    int keep = 0;
    for(int j = 0; j < k; j++){
      if(v.at(j) == 0) keep++;
    }
    int num = n - 1, ans = n - 1;
    ans -= (num / k) * keep;
    num %= k;
    for(int j = 0; j < num; j++){
      if(v.at(j) == 0) ans--;
    }
    
    ll sum = 0;
    for(int j = 0; j < k; j++){
      sum += v.at(j);
    }
    num = n - 1;
    sum *= num / k;
    num %= k;
    for(int j = 0; j < num; j++){
      sum += v.at(j);
    }
    sum += x;
    ans -= (sum / m) - (x / m);
    
    cout << ans << '\n';
  }
}