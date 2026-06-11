#include<iostream>
#include<map>
using namespace std;
main(){
  int a,b=0,c=0,n,x=0,max=0;
  map< int,int >p;
  for(a=0;a++<100;p[a]=0);
  while(cin>>n){
    if(p[n]==0){
      if(b==0||b<n)b=n;
    }
    p[n]++;
  }
  for(a=0;a<b;a++){
    if(max<p[a]){
      max=p[a];
    }
  }
  for(a=0;a<b;a++){
    if(max==p[a]){
      cout<<a<<endl;
    }
  }
  return 0;
}