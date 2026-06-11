#include<iostream>
using namespace std;

int main(){
 int h,w,m,n;
while(true){
 cin>>h>>w;
  if (h==0 && w==0) break;
  m=1;
  n=1;
 while(n<=h){
  if(n%2==1){
   while(m<=w){
    if(m%2==1){
     cout<<"#";
    } else cout<<".";
    m++;
   }
   cout<<endl;
   n++;
   m=1;
  } else {
   while(m<=w){
    if(m%2==1){
     cout<<".";
    } else cout<<"#";
    m++;
   }
   cout<<endl;
   n++;
   m=1;
  }
 }
cout<<endl;
}
return 0;
}