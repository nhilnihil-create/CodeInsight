//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
    I LOVE CLARICE STARLING

     ♥LOVE♥        ♥LOVE♥
  ♥LOVE♥♥LOVE♥  ♥LOVE♥♥LOVE♥
♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
   ♥LOVE♥♥LOVE♥♥LOVE♥♥LOVE♥
      ♥LOVE♥♥LOVE♥♥LOVE♥
         ♥LOVE♥♥LOVE♥
            ♥LOVE♥
               ♥


        EXPLAINATION BELOW->
        DP + NT
        Read Editorial first
        1)for each 1 ≤ X ≤ K, let us consider the problem “how many sequences {Ai} are there
          such that gcd(A1, ..., AN ) = X
        2)The necessary and sufficient condition of the greatest common divisor being a multiple of X(not exactly)
        is that all the A1, ..., AN are multiples of X. The number of such sequences is ⌊K/X⌋^N
        ==>since for gcd of 4== we can use 4,8,12,..but even multiple of 4 for example 12 can be created using other multiples of 4 
        such as 12,24,36..
        3)The necessary and sufficient condition of it being exactly X is that “it is a multiple of X, but
        not 2X, 3X....” If they are calculated in the decreasing order of X, it can be found by subtracting
        the number of those of 2X, 3X, ....
        ==> numbers for 4 will be n(4)-n(8)-n(12)..
      
*/
//E-Sum of Gcd of tuples(Hard)
//TC--O(K log K + K log N)klogn==> for each k we apply modularexpo.,klogk for each k we subtract 2k,3k..
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
ll dp_gcd[100005];
ll modularExponentiation(ll x,ll n,ll M)
{   
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
        result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
        return result;
}
void solve()
{
  ll n,k,gd,i;cin>>n>>k;
  ll ans=0;
  ll no_multiples=0;
  ll cases=0;
 
  for(gd=k;gd>=1;gd--)
  {
      no_multiples=k/gd;
      cases=modularExponentiation(no_multiples,n,MOD7);
      cases%=MOD7;
      ll extra_cases=0;
      for(i=2*gd;i<=k;i+=gd)
      extra_cases=(extra_cases+dp_gcd[i])%MOD7;
      
      dp_gcd[gd]=(cases-extra_cases+MOD7)%MOD7;
      
  }
  
  foe(i,1,k)
  ans=(ans+(dp_gcd[i]*i)%MOD7)%MOD7;
  
  cout<<ans<<"\n";
}
int main()
{
   fastio
   solve();
  return 0;
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
//if you want to apply lowerbound on set use s.lower_bound(key),not the one used for vector
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
