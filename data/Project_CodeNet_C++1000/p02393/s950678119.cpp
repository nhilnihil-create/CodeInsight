#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, x;
  cin>>a>>b>>c;
  if(a>=b){
      x=a;
      a=b;
      b=x;
  }
  if(a>=c){
      x=a;
      a=c;
      c=b;
      b=x;
  }else if(a<c&&c<b){
      x=b;
      b=c;
      c=x;
  }
  cout<<a<<" "<<b<<" "<<c<<endl;
  
  
  return 0;
}
