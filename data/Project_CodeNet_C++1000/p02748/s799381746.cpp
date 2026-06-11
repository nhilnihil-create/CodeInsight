#include<bits/stdc++.h>
using namespace std;
 
int main(void){
   int A,B,M;
   cin>>A>>B>>M;
   int Mini_a=200000;
   int Mini_b=200000;
   vector<int> a(A),b(B);
   for(int i=0;i<A;i++){
      cin>>a[i];
      Mini_a=min(Mini_a,a[i]);
   }
   for(int i=0;i<B;i++){
      cin>>b[i];
      Mini_b=min(Mini_b,b[i]);
   }
   vector<int> x(M),y(M),c(M);
   for(int i=0;i<M;i++){
      cin>>x[i]>>y[i]>>c[i];
   }
   int ans=1000007;
   for(int i=0;i<M;i++){
      int sum=a[x[i]-1]+b[y[i]-1]-c[i];
      ans=min(ans,sum);
   }
   cout<<min(ans,Mini_a+Mini_b)<<endl;
   return 0;
}
