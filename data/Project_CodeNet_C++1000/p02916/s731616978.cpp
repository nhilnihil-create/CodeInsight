#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   vector<int> A(N);
   int B;
   vector<int> C(N);
   
   rep(i,N){
       cin>>A[i];
   }
   int sum=0;
   rep(i,N){
       cin>>B;
       sum+=B;
   }
   rep(i,N-1){
       cin>>C[i];
   }
   
   rep(i,N-1){
       if(A[i]==A[i+1]-1){
           sum+=C[A[i]-1];
       }
   }
   cout<<sum<<endl;
   
}
