#include <bits/stdc++.h>
using namespace std;
#define int long long
int a(int H){
  if(H==1)
    return 1;
  else
    return a(H/2)*2+1;
}
signed main(){
  int H,i=0;
  cin>>H;
  cout<<a(H)<<endl;
}
