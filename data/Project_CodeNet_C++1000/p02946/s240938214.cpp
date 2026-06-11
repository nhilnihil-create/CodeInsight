#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int K,X;
   cin>>K>>X;
   for(int i=1;i<=2*K-1;i++){
   cout<<X-K+i;
   if(i<2*K-1){cout<<" ";}
   }
   cout<<endl;
return 0;}