#include<bits/stdc++.h>
using namespace std;

int main(void){
   int X;
   cin>>X;
   int rest=X%100;
   int count=X/100;
   if(5*count>=rest){
      cout<<1<<endl;
   }else{
      cout<<0<<endl;
   }
   return 0;
}
