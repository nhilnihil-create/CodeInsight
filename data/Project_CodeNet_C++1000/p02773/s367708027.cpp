#include<bits/stdc++.h>
using namespace std;




int main(void){
   int N; 
   cin>>N;
   map<string,int> a;

   for(int i=0;i<N;i++){
     string s;
     cin>>s;
     a[s]++;
   }
   int x=0;
   for(auto p : a) x=max(x,p.second);
   for(auto p : a){
      if(p.second != x) continue;
      cout<<p.first<<endl; 
   }

   return 0;
   
}


