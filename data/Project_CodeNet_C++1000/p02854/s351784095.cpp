#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<ll>asum(n);
  rep(i,n){
    int a;
    cin >> a;
    if(i != 0) asum[i] = asum[i-1];
    asum[i] += a;
  }
  ll m = 1e18;
  for(int i = 0;i <= n;i++){
    m = min(m,abs(asum[n-1]-2*asum[i]));
  }
  cout << m << endl;
}