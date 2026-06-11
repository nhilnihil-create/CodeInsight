#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   for(int i=0;i<=N;i++){
      if(floor(i*1.08)==N){
         cout<<i<<endl;
         return 0;
      }
   }
   cout<<":("<<endl;
   return 0;
}
