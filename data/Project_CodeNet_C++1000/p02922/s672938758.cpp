#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;

int main() {
  int a,b; cin >> a >> b;
  rep(i,20){
    if((a-1)*i+1>=b){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}