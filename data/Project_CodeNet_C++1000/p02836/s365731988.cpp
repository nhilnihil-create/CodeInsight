#include <bits/stdc++.h>
using namespace std;

int main(){
 string S,T;
 cin>>S;
 T=string(S.rbegin(),S.rend()); 
 int tot=0;
 int len=S.length();
 if(S.length()==len&&T.length()==len&&len>=1&&len<=100){
 for(int i=0;i<len;i++){
     if(S[i]!=T[i]){
         tot++;
     }
 }
 }
 cout<<tot/2;
   return 0;
   
}