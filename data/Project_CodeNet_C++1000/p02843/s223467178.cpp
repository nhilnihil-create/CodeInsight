#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int X;
   cin>>X;
   for(int i=1;i<=X/100;i++){
      if(X>=100*i&&X<=100*i+5*i){cout<<1<<endl;return 0;}
   }
   cout<<0<<endl;
return 0;}