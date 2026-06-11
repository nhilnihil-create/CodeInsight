//Mahir Ratanpara (DA-IICT)
#include<bits/stdc++.h>
using namespace std;
#define Ff(i,a,n) for(i=a;i<n;i++)
#define Fr(i,a,n) for(i=a;i>n;i--)
#define ll long long
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef pair<ll, ll>	pa;
typedef vector<ll>		vc;
typedef vector<pa>		vp;
typedef vector<vc>		vvc;
int mpow(int base, int exp); 
void ipgraph(ll n,ll m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vc g[N];


ll root(ll* a,ll A)
{
    while(a[A]!=A)
    {
        a[A]=a[a[A]];
        A=a[A];    
    }
    return A;    
}
 
void WeightedUnion(ll* a,ll* s,ll x,ll y)
{
    ll root_x=root(a,x);
    ll root_y=root(a,y);
	if(root_x==root_y)
	return;
    if(s[root_x]<s[root_y])
    {
        a[root_x]=a[root_y];
        s[root_y]+=s[root_x];    
    }
    else
    {
        a[root_y]=a[root_x];
        s[root_x]+=s[root_y];    
    }    
}
 
bool Find(ll* a,ll x,ll y)
{
    if(root(a,x)==root(a,y))
    return true;
    
    return false;
}


int main() {
    FAST;
    ll t, i, j, k, p, q, r, x, y, u, v, n, m;
	cin>>n;
	
	//Forming set Array and size Array.
	ll a[n],s[n];
	for(i=0;i<n;i++)
	{
		a[i]=i;
		s[i]=1;
	}

	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		x--;
		y--;
		WeightedUnion(a,s,x,y);
	}

	ll maxi=INT_MIN;
	Ff(i,0,n)
	{
		// cout<<s[i]<<" ";
		maxi=max(maxi,s[root(a,i)]);
	}
	cout<<maxi;
    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(ll n, ll m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}