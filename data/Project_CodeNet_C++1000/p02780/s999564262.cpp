#include <bits/stdc++.h>
#include <vector>
#include <set>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int k, n;
  cin >> n >> k;
  
  vector<double> exp(n);
  rep(i, n) {
    int p;
    cin >> p;
    exp[i] = (p + 1) / 2.0;
//    cout << exp[i] << endl;
  }
  
  double maxi = 0;
  rep(i, k) maxi += exp[i];
//  cout << maxi << endl;
  
  double now = maxi;
  for(int i = k; i < n ; ++i) {
//    cout << "maxi:" << maxi << ",exp[i-k]:" << exp[i-k] << ",exp[i-1]:" << exp[i] << endl;
    now = now - exp[i-k] + exp[i];
    maxi = max(maxi, now);
  }
  
  cout << fixed << maxi << endl;
    
  return 0;
}
