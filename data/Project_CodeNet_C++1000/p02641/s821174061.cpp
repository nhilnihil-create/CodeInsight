#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
 int X,N;
 cin>>X>>N;
 vector<int>p(N),q(300);
 for(int i=0;i<N;i++){
   cin>>p[i];
 }

 for(int i=0;i<300;i++){
   q[i]=i;
   for(int j=0;j<N;j++){
    if(p[j]==q[i]){
     q[i]=1111111;
     break;
    }
   }
 }
 
 int ans=11111111;
 for(int i=0;i<300;i++){
   ans=min(ans,abs(q[i]-X));
 }

   
   for(int i=0;i<300;i++){
     if(ans==abs(q[i]-X)){
       cout<<i<<endl;
       break;
    }
   }  
      
 }
 