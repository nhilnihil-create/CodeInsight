#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  int sum = 0, num=100100, m;
  rep(i,n) {
    a[i]=l+i;
    sum += a[i];
    if(num>abs(a[i])) {
      num = abs(a[i]);
      m = i;
    }
  }
  cout << sum - a[m] << endl;
  return 0;
}