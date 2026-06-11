#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){ 
 
  ll t1,t2; cin >> t1 >> t2;
  ll a1,b1,a2,b2; cin >> a1 >> a2 >> b1 >> b2;
  
  if( a1 < b1 ){ swap(a1,b1); swap(a2,b2);}
  
  ll d1 = (a1-b1)*t1; ll d2 = (a2-b2)*t2;
  
  if( d1+d2 > 0){ cout << 0 << endl;}
  else if( d1+d2 == 0 ){ cout <<"infinity" << endl;}
  else{
    
    ll k = ceil( (long double)d2/(d1+d2) );
    
    if( d1*k+d2*(k-1) < 0){ cout << 2*k-3 << endl;}
    else{ cout << 2*k-2 << endl;}
    
  }
  
  return 0;
}