#include <bits/stdc++.h>
#define ll long long
#define pb puhs_back
#define Int int64_t
using namespace std;

int N;
int main()
{
   cin>>N;
   vector<Int> A(N);
   for(auto &x:A) cin>>x;
   Int ans=0;
   for(int i=0;i<N;++i){
       for(int j=i+1;j<N;++j){
           ans+=A[i]*A[j];
       }
   }
   cout<<ans<<"\n";
}