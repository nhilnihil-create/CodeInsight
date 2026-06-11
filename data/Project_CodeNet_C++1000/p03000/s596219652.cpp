#include<iostream>
using namespace std;

main(){
  int n,a,x,d=0,s=1;
  cin>>n>>a;
  for(int i=0; i<n;i++){
    cin>>x;
    d = d+x;
    if(d<=a) s =s+1;
  }
  cout<<s<<endl;
  return 0;
}