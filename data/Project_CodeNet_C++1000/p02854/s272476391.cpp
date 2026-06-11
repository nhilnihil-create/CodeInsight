#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int64_t N;
   cin>>N;
   vector<int64_t>A(N);
   int64_t sum=0;
   for(int64_t i=0;i<N;i++){
       cin>>A[i];
       sum+=A[i];
   }
   int64_t left=0;int64_t ans=sum;
   for(int64_t i=0;i<N;i++){
   left+=A[i];int64_t right=sum-left;
   ans=min(abs(left-right),ans);
   }
   cout<<ans<<endl;
return 0;}