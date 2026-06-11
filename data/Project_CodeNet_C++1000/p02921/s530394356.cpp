#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   string S,T;
   cin>>S>>T;
   int count=0;
   for(int i=0;i<3;i++){
       if(S[i]==T[i]){count++;}
   }
   cout<<count<<endl;
return 0;}