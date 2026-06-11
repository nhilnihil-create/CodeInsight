#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n), x(n);
  rep(i,n) cin >> a[i];
  //x[0]=s-2(A1+A3+..+An-2)
  ll s = 0, A = 0;
  rep(i,n) {
    s += a[i];
    if(i%2!=0) A += a[i];
  }
  x[0] = s-2*A;
  for(int i = 1; i < n; i++) x[i] = 2*a[i-1]-x[i-1];
  rep(i,n) cout << x[i] << " ";
  cout << endl; 
  return 0;
}