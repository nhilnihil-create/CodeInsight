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
ll n;
vector<string>ans ;
void fun(ll i,ll j,string s)
{
    if(i==n)
    {
        ans.pb(s) ;
    }
    else
    {
        string ns=s ;
        for(ll k=0;k<j;k++)
        {
            ns=s ;
            ns+=(char)('a'+k) ;
            fun(i+1,j,ns) ;
        }
        if(s.length()==0)
            return ;

        if(j<26)
        {
            ns=s ;
            ns+=(char)('a'+j) ;
            fun(i+1,j+1,ns) ;
        }



    }
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
     cin>>n ;

     fun(0,1,"") ;

     sort(all(ans)) ;

     for(string s:ans)
        cout<<s<<endl ;





   }
}
/// ans ->for answer
/// cur ->for local answer
/// level ->for depth in tree
/// v -> adjacency matrix
/// r -> array
/// s ->string

