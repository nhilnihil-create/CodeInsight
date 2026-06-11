#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int sum=0;
  rep(i,n){
    for(int j=i+1;j<n;j++){
      sum += a[i]*a[j];
    }
  }
  
  cout << sum << endl;
  
  return(0);
}