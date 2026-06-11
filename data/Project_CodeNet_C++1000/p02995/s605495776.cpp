//Author- VMAX


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_multiset tree<long long , null_type,less_equal<long long >, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<long long , null_type,less<long long >, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define YES cout<<"YES"<<"\n";
#define NO cout<<"NO"<<"\n";
#define ld     long double 
#define yes cout<<"yes"<<"\n";
#define no cout<<"no"<<"\n";
#define No cout<<"No"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define f(i,a) for(i=0;i<a;i++)
#define fo(i,a) for(i=1;i<=a;i++)
#define fa(i,a) for(auto i:a)
#define r(i,a) for(auto i=a.rbegin();i!=a.rend();i++)
#define en cout<<"\n";
#define ull unsigned long long int
#define o(x) cout<<x<<"\n";
#define o1(x) cout<<x<<" ";
#define pb push_back
#define F first
#define in insert
#define mp make_pair
#define S second
#define pre(n) cout<<fixed<<setprecision(n);
#define      gcd(a,b)    __gcd(a,b)
#define bs            binary_search
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>t;while(t-->0)
const ll Mod = 998244353;
#define mod 1000000007
#define pi 3.14159265358979323846
#define all(x) x.begin(),x.end()
#define re return 0;
// *#######################################################################################*

/*
bool isp(ll n)
{
    ll i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
        
    }
}
  */
  long long lcm(long long a, long long b){//最小公倍数を求める
   return a * b / gcd(a, b);
}
       int main()
       
       {
        fast
        
          ll a,b,c,d;
          cin>>a>>b>>c>>d;
          a--;
          ll z=lcm(c,d);
          ll s=b-a-((b/c)+b/d-b/z-a/d-a/c+a/z);
          o(s)

        
 
          re
}
