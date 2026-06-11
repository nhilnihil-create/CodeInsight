#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a, b, c; cin >> a >> b >> c;
  string ans="No";
  
  if(4*a*b<(c-a-b)*(c-a-b) && 0<(c-a-b)) ans = "Yes";
  cout << ans << endl;
}
