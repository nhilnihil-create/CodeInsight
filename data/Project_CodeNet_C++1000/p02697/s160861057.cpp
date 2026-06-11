#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,m;
  cin >> n >> m;
  rep(i,(m+1)/2){
    cout << i+1 << " " << (m+1)/2*2-i << endl;
  }
  rep(i,m/2){
    cout << n-m/2*2+i << " " << n-i << endl;
  }
  return 0;
}
