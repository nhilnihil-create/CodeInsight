#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   string S;
   cin>>S;
   set<char>k;
   for(int i=0;i<4;i++){
       k.insert(S[i]);
   }
   if(k.size()==2){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
return 0;}