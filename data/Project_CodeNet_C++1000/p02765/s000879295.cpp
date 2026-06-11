#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int N,R;
  cin >> N >> R;
  if(N>9) cout << R << endl;
  else cout << 100*(10-N)+R << endl;
  
  return 0;
}
