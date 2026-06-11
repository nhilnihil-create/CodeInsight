#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int sum = 0;
  rep(i,n){
    rep(j,n){
      sum += a.at(i) * a.at(j);
    }
    sum -= a.at(i) * a.at(i);
  }
  cout << sum/2 << endl;
  }
