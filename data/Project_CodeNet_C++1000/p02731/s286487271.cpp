#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  double l; cin >> l;
  double v = (l*l*l) / 27;
  
  cout << fixed << setprecision(10);
  cout << v << endl;
  
  return 0;
}
