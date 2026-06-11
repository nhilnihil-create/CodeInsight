#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int a,b;
  cin >> a >> b;
  
  int x = 2*b + 1;
  
  if(a%x == 0) cout << a/x << endl;
  else cout << a/x + 1 << endl;

}
