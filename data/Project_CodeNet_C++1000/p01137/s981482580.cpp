#include<bits/stdc++.h>
using namespace std;
int main(){
  int e;
  while(cin>>e&&e){
    int i,j,a,y,m=1000000000;
    for(i=1;i*i*i<=e;++i);
    a=i-1;
    for(i=0;i<=a;++i){
      int b=e;
      b=b-i*i*i;
      for(j=1;j*j<=b;++j);
      y=(j-1);
      b=b-y*y;
      m=min(m,b+y+i);
    }
    cout<<m<<endl;
  }
  return 0;
}

