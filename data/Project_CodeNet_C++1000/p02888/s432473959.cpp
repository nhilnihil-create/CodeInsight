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
   sort(A.begin(),A.end());
   for(int i=N-1;i>=0;--i){
       for(int j=i-1;j>=0;--j){
           Int sum=A[i]+A[j];
           auto itr=lower_bound(A.begin(),A.end(),sum);
           Int x=distance(itr,A.end());
           ans+=(N-1-x)-i;
           
       }
   }
   cout<<ans<<"\n";
}