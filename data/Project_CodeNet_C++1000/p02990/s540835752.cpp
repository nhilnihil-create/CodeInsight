#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,K,Q=1000000007,P=Q-2;
  cin>>N>>K;
  for(int64_t i=1;i<=K;i++){
    int64_t Z=0;
    if(N-K+1>=i){
    int64_t A=N-K+1,B=min(i,N-K+1-i),C=1;
      for(int j=1;j<=B;j++){
        C=(C*(A+1-j))%Q;
        int64_t N=P;
       int64_t a=1,b=0,c=1;
       while(N>0){
         a*=2;
         if(N%a!=0){
           N-=a/2;
           int64_t d=j;
           for(int j=0;j<b;j++){
            d=d*d;
             d=d%Q;
          }
           c=c*d;
          c=c%Q;
         }
        b++;
      }
        C=(C*c)%Q;
      }
      Z=(Z+C)%Q;
    }
    
    int64_t A=K-1,B=min(K-i,i-1),C=1;
      for(int j=1;j<=B;j++){
        C=(C*(A+1-j))%Q;
        int64_t N=P;
       int64_t a=1,b=0,c=1;
       while(N>0){
         a*=2;
         if(N%a!=0){
           N-=a/2;
           int64_t d=j;
           for(int j=0;j<b;j++){
            d=d*d;
             d=d%Q;
          }
           c=c*d;
          c=c%Q;
         }
        b++;
      }
        C=(C*c)%Q;
      }
      Z=(Z*C)%Q;
    cout<<Z<<endl;
  }
    
        
}


