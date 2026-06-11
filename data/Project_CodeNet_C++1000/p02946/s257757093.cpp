#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int K,X;
   cin>>K>>X;
   for(int i=X-K+1;i<X+K;i++){
   cout<<i;
   if(i<X+K){cout<<" ";}
   }
   cout<<endl;
return 0;}