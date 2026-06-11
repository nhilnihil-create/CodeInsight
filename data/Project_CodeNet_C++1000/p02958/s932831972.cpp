#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  vector<int> q(p);
  sort(q.begin(), q.end());
  int count = 0;
  rep(i, n){
    if (p[i] == q[i]) count++;
  }
  if (count >= n-2) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}