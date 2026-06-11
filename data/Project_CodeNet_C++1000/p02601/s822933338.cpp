#include<bits/stdc++.h>

using namespace std;

int main(){
  int x,y,z,k;
  cin>>x>>y>>z>>k;
  while(y<=x&&k) y*=2,k--;
  while(z<=y&&k) z*=2,k--;
  if(x<y&&y<z) cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}