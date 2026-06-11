#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  
  int x = max(a*c, b*c), y=max(a*d, b*d);
  
  cout<<max(x, y);
  return 0;
}