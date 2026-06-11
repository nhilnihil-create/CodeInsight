#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   bool OK=true;
   map<char,int> data;
   rep(i,4){
      data[S[i]]++; 
   }
   if(data.size()!=2){
       OK=false;
   }
   for(auto p:data){
       auto v=p.second;
       if(v!=2){
           OK=false;
       }
   }
   if(OK==true){
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
}