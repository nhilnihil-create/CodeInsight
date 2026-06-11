#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a,v,b,w;
  cin >> a  >>  v >> b >> w;
  ll t;
  cin >> t;
  bool ok = false;
  if(a==b) ok = true;
  else{
    if(w>=v) ok = false;
    else{
      if((v-w)*t >= abs(a-b)) ok = true;
      else ok = false;
    }
  }
  cout << ((ok)?"YES":"NO") << endl;
  
  return 0;
    

}
