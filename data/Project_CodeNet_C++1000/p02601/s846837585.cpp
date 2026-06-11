#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(ll i=0;i<ll(n);i++)

int main(){
 int a=0, b=0, c=0, d=0, k=0;
  cin >> a >> b >> c;
  cin >> k;
  while(a >= b){b *= 2; d++;}
  while(b >= c){c *= 2; d++;}
  
  if (d <= k) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
  
}
