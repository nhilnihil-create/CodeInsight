#include <bits/stdc++.h>
using namespace std;

int main(){
   int N,K;
   cin>>N>>K;
   vector<int> A(N+1,0);
   for(int i=0;i<K;i++){
       int kk;
       cin>>kk;
       for(int j=0;j<kk;j++){
           int ss;
           cin>>ss;
           A[ss]++;
       }
   }
   int ans=0;
   for(int i=1;i<N+1;i++){
       if(A[i]==0)ans++;
   }
   cout<<ans<<endl;
}
