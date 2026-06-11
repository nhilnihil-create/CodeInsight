#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){ 
  ll t1,t2; cin >> t1 >> t2;
  ll a1,a2; cin >> a1 >> a2;
  ll b1,b2; cin >> b1 >> b2;
  
  if( a1 < b1){ swap(a1,b1); swap(a2,b2);}
  
  ll P = (a1-b1)*t1; ll Q = (a2-b2)*t2;
  
  if( P+Q > 0){ cout << 0 << endl; return 0;}
  else if( P+Q == 0){ cout << "infinity" << endl; return 0;}
  else{
    //ここらへんがおかしい
    ll np;
    
    if( -Q % (-(P+Q))  == 0){ np = (Q/(P+Q))-1;}
    else{ np = (Q/(P+Q));}
    
    
    ll ans = 2*np-1;
    if( (np+1)*P + np*Q == 0){ ans++;}
    
    cout << ans << endl;
    
    return 0;
  }
}