#include<iostream>
 using namespace std;

 int main(){
     long long  a,b,c,d;
     long long max;
    std:cin>>a>>b>>c>>d;
   long long m1=a*c;
   long long m2=a*d;
   long long m3=b*c;
   long long m4=b*d;
    if(m1>m2)
    max=m1;
    else max=m2;
    if(max<m3)
    max=m3;
    if(max<m4)
    max=m4;
   cout<<max<<"\n"<<endl;

 }