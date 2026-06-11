/* the logic is pretty simple 
 we are following a simple series in this ques
 n -> 2*floor(n/2) -> 4*floor(n/4) -> 8*floor(n/4).....
 
 the ans=biggest power of 2 which doesnt exceed n;
 */



#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
int main()
{
  ll n;
  cin>>n;
  
  ll ans=1;
  while(2*ans<=n)
  {
    ans*=2;
  }
  cout<<2*ans-1<<endl;
}
