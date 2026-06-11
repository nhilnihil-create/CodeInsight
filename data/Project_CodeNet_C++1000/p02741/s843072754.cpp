#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=10001 ;
ll  power(ll  i,ll  j)
{
    if(j==0)
    return 1 ;
    ll t=power(i,j/2)%maa ;
    if(j%2==0)
    return (t%maa*t%maa)%maa ;
    else
    return ((t%maa*t%maa)%maa*(i%maa)%maa)%maa ;
}
int main()
{
   fast ;
   ll tests=1 ;
  // cin>>tests ;
   for(ll testcase=1;testcase<=tests;testcase++)
   {
      ///cout<<"Case #"<<testcase<<": " ;
      ///Read,Think ans Test Properly,then code
      ///Try to avoid using print statements debug on your own

      ll ar[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51} ;
      ll k ;
      cin>>k ;
      cout<<ar[k-1] ;



   }
}
/// ans ->for answer
/// cur ->for local answer
/// level ->for depth in tree
/// v -> adjacency matrix
/// r -> array
/// s ->string

