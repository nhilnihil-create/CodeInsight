#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n,a,b;
  cin >> n >> a >> b;
  long long int ans,p;
  p = n/(a+b);
  ans = p*a;
  p = n%(a+b);
  if(p < a) {
    ans += p;
  } else {
    ans += a; 
  }
  cout << ans << endl;
}