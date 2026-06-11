#include<iostream>
using namespace std;

main(){
   int i,n;
   long long int r;
  r=1;
  cin>>n;
  for(i=1;i<=n;++i){
    r=r*i;
  }
 cout<<r<<endl;
}