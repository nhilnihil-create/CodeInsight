#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


int main(void){
   int a,b,x;
   cin>>a>>b>>x;
   double PI=acos(-1);
   double y=(double)x/(double)a;
   double g;
   if(2*y<=a*b){
      g=atan2(b,2*y/b);
   }else{
      g=atan2(2*(a*b-y)/a,a);
   }
   cout<<fixed;
   cout<<setprecision(7)<<g/PI*180<<endl;
   return 0;
}