//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define test ll t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long
#define int long long
#define ull unsigned long long
#define MAX 1000005
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define vs vector<string>
#define mii map<int,int>
#define msi map<string,int>
#define vpii vector< pair<int, int > >
#define vpsi vector< pair< string ,int > >
#define forci(p,q) for(int i=p;i<q;i++)
ll gcd(ll a,ll b){ if(b==0) return a;    return gcd(b,a%b);}
ll lcm(ll a,ll b) { return (a/gcd(a,b)*b);}
ull power(ull a, ull b) {a %= mod;  ull res = 1;  while (b > 0) { if (b & 1) res = res * a % mod;  a = a * a % mod;  b >>= 1; }  return res%mod; }
ll modmul(ll x, ll y){return (x*y)%mod;}
ll modadd(ll x, ll y){return (x+y)%mod;}
ll modsub(ll x, ll y){return (x-y+mod)%mod;}
ll fact[1000007]={0};
void facto() {fact[0]=1;fact[1]=1;for(int i=2;i<1000007;i++)fact[i]=(fact[i-1]*i)%mod;}
ll ncr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(power(fact[r],mod-2)))%mod; res=(res*(power(fact[n-r],mod-2)))%mod; return res;}
ll npr(ll n,ll r) {ll res=1; res=fact[n]; res=(res*(power(fact[n-r],mod-2)))%mod; return res;}
inline long long toint(const std::string &s) {std::stringstream ss; ss << s; long long x; ss >> x; return x;}
inline std::string tostring(long long number) {std::stringstream ss; ss << number; return ss.str();}
inline std::string tobin(long long x) {return std::bitset<63>(x).to_string();}
using namespace std;
set<int> g;
void prime(int n)  
{
    while (n % 2 == 0)  
    {  
        g.insert(2);
        n = n/2;  
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    { 
        while (n % i == 0)  
        {  
            g.insert(i);  
            n = n/i;  
        }  
    }  
 	  if (n > 2)  
    	g.insert(n);
}  
int solve()
{
	int n;	
	cin>>n;
	int cnt=0;
	prime(n);
	for(auto it=g.begin();it!=g.end();it++){
		int x=*it;
		int temp=*it;
		int raise=1;
		while(n%x==0){
			n/=x;
			++cnt;
			++raise;
			x=pow(temp,raise);
		}
	}
	cout<<cnt<<endl;
	return 0;
}
signed main()
{
	fastio;
//	test
		solve();
}