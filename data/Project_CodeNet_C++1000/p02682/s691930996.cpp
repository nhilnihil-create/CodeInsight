#include<iostream>
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(a>=k)
    cout<<k;
  else if(k>a){
    if(k-a<=b)
    cout<<a;
    else if(k-a>b)
      cout<<2*a+b-k;
  }
}
 