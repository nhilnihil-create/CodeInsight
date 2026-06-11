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
ll maxi=1e6;
vc spf(maxi+1,0);

void sieve()
{
	ll i=0,j=0;
	Ff(i,0,maxi+1)
	spf[i]=-1;

	for(i=2;i<=maxi;i++)
	{
		if(spf[i]==-1)
		{
			for(j=i;j<=maxi;j+=i)
			{
				if(spf[j]==-1)
				{
					spf[j]=i;
				}
			}
		}
	}
}

map<ll,ll> get_Factors(ll x)
{
	map<ll,ll> res;
	while(x>1)
	{
		res[spf[x]]++;
		x/=spf[x];
	}
	return res;
}
map<int, int> primeFactorization(int n){
    map<int, int> ret;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
        ret[i]++;
        n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}
 
int main(){
    int n;
    cin >> n;
	int i=0;
    vector<int> a(n);
    Ff(i,0,n){
        cin >> a[i];
    }
 
    map<int, int> primes;
    for(auto x : a){
        auto tmp = primeFactorization(x);
        for(auto y : tmp){
            primes[y.first]++;
        }
    }
 
    string ans = "pairwise coprime";
    bool flag1 = false;
    for(auto x : primes){
        if(x.second == n){
            ans = "not coprime";
            break;
        }
        if(x.second != 1){
            ans = "setwise coprime";
        }
    }
 
    cout << ans << endl;
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