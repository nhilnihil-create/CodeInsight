#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N;
  cin >> N;
  ll m=0;
  for (ll i=1; i<=pow(10,6)+1; i++) {
    if (N<i*i) {
      m=i-1;
      break;
    } 
  }
  
  int n;
  for (ll i=m; i>=1; i--) {
    if (N/i*i==N) {
      n=i;
      break;
    }
  }
  
  cout << N/n+n-2 << endl;
}