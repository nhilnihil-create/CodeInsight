#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main() {
  LL N,M,A,B=0;
  cin>>N>>M;
   for(int i=0; i<M; i++){
     cin>>A;
     B=B+A;
     if(N<B){
       cout<<-1<<endl;
       break;
     }
   }
   if(N>=B){
     cout<<N-B<<endl;
   }
}
