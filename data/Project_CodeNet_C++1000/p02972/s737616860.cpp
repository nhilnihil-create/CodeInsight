#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  set<int> b;
  for(int i = n-1; i >= 0; i--) {
    int j = 2;
    int num = 0;
    while((i+1)*j<n+1) {
      if(b.count((i+1)*j)) num++;
      j++;
    }
    if(num%2!=a[i]) {
      b.insert(i+1);
    }
  }
  cout << b.size() << endl;
  for(auto p : b) cout << p << endl;
  return 0;
}