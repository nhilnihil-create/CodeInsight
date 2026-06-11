#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int b1 = 0;
  rep(i, n){
    cin >> a[i];
    if (i % 2 == 0) b1 += a[i];
    else b1 -= a[i];
  }
  cout << b1 << ' ';
  int b = b1;
  rep(i, n-1){
    b = 2 * a[i] - b;
    if (i == n-2) cout << b << endl;
    else cout << b << ' ';
  }
  
  return 0;
}