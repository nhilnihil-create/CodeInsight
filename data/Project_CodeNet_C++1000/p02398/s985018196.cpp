
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,cnt=0;
  cin>>a>>b>>c;
  if(a>b) swap(a,b);
  for(int i=a;i<=b;++i){
    if(c%i==0) ++cnt;
  }
  cout<<cnt<<endl;
  return 0;
}
