#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  for(;;){
    a-=d;
    c-=b;
    if(c<=0){
      cout<<"Yes";
      return 0;
    }else if(a<=0){
      cout<<"No";
      return 0;
    }
  }
}
