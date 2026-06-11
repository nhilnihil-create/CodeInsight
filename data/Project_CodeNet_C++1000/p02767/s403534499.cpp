#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  int n; cin >> n;
  vector<int> x(n);
  rep(i,n)cin >> x[i];
  int minv = 1e9;
  for(int i = 1; i <=100 ;++i) {
    int sum = 0;
    rep(j,n){
      sum += (x[j]-i)*(x[j]-i);
    }
    minv = min(minv,sum);
  }
  cout << minv << endl;
  return 0;
}