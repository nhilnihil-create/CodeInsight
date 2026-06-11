//*******************************By Harry Singh From Phillaur.
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000006
const ll mo=1000000007;
#define string_to_any_base(s,base) stoll(s, 0, base);
#define vc vector
// #define mp map<ll,ll> mp;
#define bt(M,value) bitset<M> b(value)
#define S set<ll> s;
#define pb push_back
#define ST set<string> s;
#define INF 1e15
using namespace std;
set<ll> primes;
vector<pair<ll,ll>> adj[MAX];
vector<ll> ad[MAX];
typedef pair<int,int> ip;
///******************************ALL important functions;
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);} 
ll lcm(ll a, ll b)  {  return (a*b)/gcd(a, b);  } 
void Sieve(){ bool prime[MAX+1]; memset(prime, true, sizeof(prime)); for (int p=2; p*p<=MAX; p++) { if (prime[p] == true) {for (int i=p*p; i<=MAX; i += p) prime[i] = false; } } for(int i=2;i<=MAX;i++)if(prime[i]==true)primes.insert(i);} 
ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;}
ll modpow(ll a, ll n=mo-2) {ll r=1;while(n)r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;return r;}
int visited[MAX]={0};
void dfs(int u)
{
	visited[u]=true;
	for(auto s:ad[u])
	if(!visited[s])dfs(s);
}

int main()
{
int n,k;;cin>>n>>k;
if(k>(((n-1)*(n-2))/2))
cout<<"-1\n";
else
{	vc<ip> v;
	for(int i=2;i<=n;i++)
	v.pb({1,i});
	int left=(((n-1)*(n-2))/2)-k;
	for(int i=2;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(left==0)goto m;
			v.pb({i,j}),--left;
		}
	}
	m:
	cout<<v.size()<<"\n";
	for(auto s:v)cout<<s.first<<" "<<s.second<<"\n";
	
}
}
