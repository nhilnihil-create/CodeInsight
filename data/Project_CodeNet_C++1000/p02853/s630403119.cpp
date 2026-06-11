#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y;cin>>X>>Y;
  int ans = 0;
  if(X<4) ans += (4-X)*100000;
  if(Y<4) ans += (4-Y)*100000;
  if(X*Y==1){ ans+=400000;}
  cout<<ans<<"\n";
}
