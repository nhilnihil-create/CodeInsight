/* the logic is pretty simple 
 we are following a simple series in this ques
 n -> 2*floor(n/2) -> 4*floor(n/4) -> 8*floor(n/4).....
 
 the ans=biggest power of 2 which doesnt exceed n;
 
 there is  a shortcut method to compute the biggest power of 2 that doesnt excceed k;
 
 b=1LL<<(63-_buitin_clzll(k)
 ans =2*b-1;
 */



#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
int main()
{
  ll n;
  cin>>n;
  ll b=1LL<<(63-__builtin_clzll(n));
  
  cout<<2*b-1<<endl;
  
  
}
