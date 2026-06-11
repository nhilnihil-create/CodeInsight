#include<iostream>
using namespace std;

int main(){
 int h,w,i,n;
while(true){
 cin>>h>>w;
  if (h==0 && w==0) break;
  i=1;
  n=1;
  while(i<=w){
   cout<<"#";
   i++;
  } cout<<endl;
  n=2;
  i=1;
  while(2<=n && n<=(h-1)){
   cout<<"#";
   i=2;
    while(2<=i && i<=(w-1)){
     cout<<".";
     i++;
    }
  cout<<"#"<<endl;
  n++;
  }
 i=1;
 while(i<=w){
   cout<<"#";
   i++;
 } cout<<endl;
 cout<<endl;
}
   
return 0;
}