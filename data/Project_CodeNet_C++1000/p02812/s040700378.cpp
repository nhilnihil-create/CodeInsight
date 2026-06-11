#include <bits/stdc++.h>
using namespace std;

int main(){
 string S,T;
 T="ABC";
 int N;
 int tot=0;
 cin>>N>>S;
 for(int i=0;i<N;i++){
     if(S[i]==T[0]&&S[i+1]==T[1]&&S[i+2]==T[2]){
         tot++;
     }
 }
 if(N>=3&&N<=50&&S.length()==N){
     cout<<tot;
 }
   return 0;
   
}