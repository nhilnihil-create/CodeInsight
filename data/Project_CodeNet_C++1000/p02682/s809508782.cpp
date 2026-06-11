#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  ll a,b,c,k,ans;
  cin >> a >> b >> c >> k;
  
  if(k <= a){ans = k;}
  else if(k <= a+b){ans = a;}
  else{ans = a-(k-a-b);}
  
  
  cout << ans << endl;
  
  return 0;
}
