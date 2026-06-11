#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  int n; cin >> n;
  for(int i = 1; i <= 50000; ++i){
    int x = floor(i*1.08);
    if(x==n){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}