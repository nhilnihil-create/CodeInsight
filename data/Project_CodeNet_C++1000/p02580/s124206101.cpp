#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define tf(x) get<0>(x)
#define ts(x) get<1>(x)
#define tt(x) get<2>(x)
#define endl '\n'
#define F first
#define S second 
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ve vector <int>
#define vep vector<pii >
#define mod 1000000007
#define maxn 2e5+5
#define ld long double
#define in insert
#define fr(i,a,b) for(int i=a;i<b;i++)
#define forn(i,n) for(int i=0;i<n;i++)
#define fora(m) for(auto it:m)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define input_array int n;cin>>n;int a[n];forn(i,n) cin>>a[i];
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int mull(int  a,int b)  { 
    return ((a%mod)*(b%mod))%mod;
} 

int power(int x, int y, int p) 
{ 
    int res = 1;     
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
}

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

//--------------------------------SIEVE---------------------------//
/*bool prime[maxn]; 
int spf[maxn];
void sieve() {
	forn(i,maxn) {
		prime[i]=true;
		spf[i]=i;
	}
	fr(i,2,maxn) {
		if(prime[i]){
			for(int j=2*i;j<maxn;j+=i) {
				prime[j]=false;
				spf[j]=i;
			}
		}
	}
}*/

//-----------------------------End---------------------------------//


//------------------------------------------------DFS------------------------//
/*bool stat[maxn];
int depth[maxn],par[maxn];
void init_graph() {
	memset(stat,false,sizeof(stat);
	memset(depth,0,sizeof(depth);
	for(int i=0;i<maxn;i++) par[i]=i;
}
void dfs(int u,int p) {
	stat[u]=true;
	depth[u]=depth[p]+1;
	par[u]=p;
	for(auto it:g[u]) {
		if(stat[it]==false)
			dfs(it,u);
	}
}*/

//-------------------------------------DFS-END--------------------------------//

//-----------------------------------nCr%p-----------------------------------//
/*int nCr(int n, int r) 
{ 
   if (r==0) 
      return 1; 
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%mod; 
  
    return (fac[n]* modInverse(fac[r], mod) % mod * 
            modInverse(fac[n-r], mod) % mod) % mod; 
} */
//---------------------------------EnD---------------------------------------//

void solve() {
	int r,c,n;
	cin>>r>>c>>n;
	int h1[r+1]={0},h2[c+1]={0};
	vep v(n);
	forn(i,n) {
		cin>>v[i].F>>v[i].S;
		v[i].F--;v[i].S--;
	}
	fora(v) {
		h1[it.F]++;
		h2[it.S]++;
	}
	int mx1=-1,row;
	for(int i=0;i<r;i++) {
		if(h1[i]>mx1) {
			mx1=h1[i];
			row=i;
		}
	}
	set <int> rw,co;
	for(int i=0;i<r;i++) {
		if(h1[i]!=mx1) h1[i]=0;
	}
	mx1=-1;
	int col;
	for(int i=0;i<c;i++) {
		if(h2[i]>mx1) {
			mx1=h2[i];
			col=i;
		}
	}
	fr(i,0,c) {
		if(mx1==h2[i]) co.in(i);
	}
	ve vec[r+1];
	for(auto it:v) {
		if(h1[it.first]) {
			//cout<<it.first<<endl;
			vec[it.first].pb(it.second);}
	}
	//cout<<vec[1].size()<<endl;
	for(int i=0;i<r;i++) {
		ve aux;
		if(vec[i].size()==0) continue;
		//cout<<vec[i].size()<<endl;
		for(int j=0;j<vec[i].size();j++) {
			//cout<<itr<<endl;
			int itr=vec[i][j];
			//cout<<itr<<endl;
			if(co.find(itr)!=co.end()) {
				aux.pb(itr);
				co.erase(itr);
			}
		}
		if(co.size()) {
			col=*co.begin();
			row=i;
			break;
		}
		else {
			for(auto it:aux)co.in(it);
		}
	}
	int ans=0;
	for(auto it:v) {
		if(it.second==col || it.first==row) ans++;
	}
	cout<<ans;
}
signed main() {
	IOS
	int t=1;
//	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}