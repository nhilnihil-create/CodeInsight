#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin>>N;
 string S;
 cin>>S;

 int k=0;
 for(int i=0;i<N;i++){
   if(S[i]=='R'){
     k++;
   }
 }

 int l=0,m=0;
 for(int i=0;i<k;i++){
   if(S[i]=='W'){
     l++;
   }
 }
 for(int i=k;i<N;i++){
   if(S[i]=='R'){
     m++;
   }
 }
 cout<<max(l,m)<<endl;
}