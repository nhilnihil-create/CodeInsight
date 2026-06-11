#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
   int X;
   cin>>X;
   bool a=false;
   rep(i,1007){
    if(i*100<=X&&X<=i*105){
           a=true;
           break;
       }
   }
   if(a==true){
       cout<<1<<endl;
   }
   else
   {
       cout<<0<<endl;
   }
}