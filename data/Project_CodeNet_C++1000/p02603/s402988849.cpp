#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  ll x = 1000;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n-1) if(a[i] < a[i+1]) x = x%a[i]+(x/a[i])*a[i+1];
  cout << x << endl;
}