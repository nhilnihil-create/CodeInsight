#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  
 string S,T;
 cin>>S>>T;
 
 int s=S.size(),t=T.size();
 vector<int>count(s-t+1);

 for(int i=0;i<s-t+1;i++){
   for(int j=0;j<t;j++){
     if(S[i+j]==T[j]){
       count[i]++;
     }
   }
 }

 sort(count.begin(),count.end());

 cout<<t-count[s-t]<<endl;
 
}