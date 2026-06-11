#include <bits/stdc++.h>
using namespace std;

int main() {
  int M;
  cin >> M;
  int D;
  cin >> D;
  
  int t=D/10;
  int o=0;
  if(t>=1) o=9;
  int q=D-(t*10);
  int ans=0;
  
  if(M<4 || t<=1) cout << 0 << endl;
  else if(o==0 && q<=1) cout <<0 << endl;
    
  else if(q!=9 && M>=4 && t>1 && o>1){
    for(int i=2; i<t; i++){
      for(int j=2; j<=o; j++){
        if(M>=i*j) ans++;
      }
    }
    if(q>1){
      for(int i=2; i<=q; i++){
        if(M>=i*t) ans++;
      }
    }
    cout << ans << endl;
  }
  
  else if(q==9 && M>=4 && t>1){
    for(int i=2; i<=t; i++){
      for(int j=2; j<=q; j++){
        if(M>=i*j) ans++;
      }
    }
    cout << ans << endl;
  } 
}