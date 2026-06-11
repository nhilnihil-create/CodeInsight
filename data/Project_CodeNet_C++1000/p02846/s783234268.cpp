#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  C-=E,D-=F;
  E=A*C,F=B*D;
  if(E<0)E*=-1,F*=-1;
  if(E+F>0)puts("0");
  else if(E+F==0)puts("infinity");
  else if(E%(-E-F))cout<<E/(-E-F)*2+1<<endl;
  else cout<<E/(-E-F)*2<<endl;
}