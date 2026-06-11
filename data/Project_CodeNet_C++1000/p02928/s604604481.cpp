#include<bits/stdc++.h>
using namespace std;
#define int                 long long
#define FF(i,a,b)           for(int i=a;i<b;i++)
#define BF(i,a,b)           for(int i=a;i>=b;i--)
#define vi                  vector<int>
#define MAP                 map<int,int>
#define pb                  push_back
#define MP                  make_pair
#define F                   first
#define S                   second
#define pi                  pair<int,int>
#define all(v)              v.begin(),v.end()
#define PIE                 3.1415926535897932384626433832795
#define print0(a)           cout<<a<<"\n"
#define print1(a)           cout<<a<<' '
#define print2(a,b)         cout<<a<<" "<<b<<" ";
#define print3(a,b,c)       cout<<a<<" "<<b<<" "<<c<<" ";
#define print4(a,b,c,d)     cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
#define FastIO              ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
/**************************************************************************************/
                       /*Global Variables*/
const int mod = 1e9+7;
const int N = 2e5+10;
const int inf = 1e18;
vector<int> g[N];
int h,w;
/**************************************************************************************/
template <typename A>istream& operator>>(istream& input,vector<A>& x) {for(auto& i:x)input>>i;return input;}
template<typename A>ostream& operator<<(ostream& output,vector<A>& x) {for(auto& i:x)output<<i<<' ';return output;}
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
int add(int a, int b){return (a%mod + b%mod + mod)%mod;}
int sub(int a, int b){return (a%mod - b%mod + mod)%mod;}
int mul(int a, int b){return ((a%mod)*(b%mod) + mod)%mod;}
int Power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int PowerMod(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res=mul(res,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return res;
}
signed main()
{
    
    // string s1,s2;
    // cin>>s1>>s2;
    // freopen(s1,"r",stdin);
    // freopen(s2,"w",stdout);
    
    FastIO;
    int T=1;
   // cin>>T;
    while(T--)
    {
       int n,k;
       cin>>n>>k;
       vi a(n);
       cin>>a;
       vi dis(n,0);
       int ans = 0;
       int cnt=0;
       FF(i,0,n)
       {
            //cnt=0;
           FF(j,i+1,n)
           {
               if(a[j]<a[i])cnt++;
           }
           

       }
       ans=cnt*k;
       ans%=mod;
       FF(i,0,n)
       {
           FF(j,0,n)
           {
               if(a[j]<a[i])dis[i]++;
           }
       }
      // cout<<dis<<"\n";
       
       FF(i,0,n)
       {
           int d = dis[i];
           int val = (k*(k-1));
           val%=mod;
           val*=d;
           val%=mod;
           val*=PowerMod(2,mod-2);
           val%=mod;
           ans+=val;
           ans%=mod;

       }
       cout<<ans<<"\n";
       
    }

}
/*
|| Do what you can with all you have,wherever you are. ||

|| Knowing is not enough, we must apply. Wishing is not enough, we must do. ||

|| A goal is a dream with deadline. ||

|| Whether you think you can or you think you can't, you're right. ||
*/

