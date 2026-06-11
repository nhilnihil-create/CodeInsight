#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e6+2;
int divisor_count[N];

int main(){
   int n;
   cin>>n;
   int i,j;
   memset(divisor_count,0,sizeof(divisor_count));
   for(i=1;i<=N;++i){
      for(j=i;j<=N;j+=i){
         divisor_count[j]++;
      }
   }
   ll ans=0;
   for(i=1;i<=n-1;++i){
      ans+=1LL*divisor_count[i];
   }
   cout<<ans;
}