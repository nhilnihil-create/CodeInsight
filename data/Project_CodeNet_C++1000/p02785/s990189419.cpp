#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll cnt = 0;
  for(int i = k; i < n; i++){
    cnt += a.at(i);
  }
  cout << cnt << endl;
  
  
}