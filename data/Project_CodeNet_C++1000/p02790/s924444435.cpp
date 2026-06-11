#include <bits/stdc++.h>
#include <vector>
#include <set>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  if(a >= b) rep(i, a) cout << b;
  else rep(i, b) cout << a;
  cout << endl;
    
  return 0;
}
