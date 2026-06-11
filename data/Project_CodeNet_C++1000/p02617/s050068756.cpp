//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 

 
ll MOD=1e9 + 7;
ll OO=1e9 + 100;
const int N=1e6 + 2,M=10 + 1;
int lvl[N];
ll comp[N];


ll n,m,k,T,cnt,SU;
int a,b,c,d;
ll l,r,mid;
vector<int> vec;
int val;

vector<int> adj[N];

ll SolveInc(){
	ll cnt = 0;
	for(int i=1;i<=n;++i)
		lvl[i] = SZ(adj[i]);
	
	ll len = 1;
	for(int i=n;i;--i){
		
		cnt += comp[i] = len;
		len += lvl[i] - 1;
		
		for(int j:adj[i])
			lvl[j]--;

	}
	return cnt;
}

ll SolveDec(){
	ll cnt = 0;
	for(int i=1;i<=n;++i)
		lvl[i] = SZ(adj[i]);
	
	ll len = 1;
	for(int i=1;i<=n;++i){
		
		cnt += comp[i] = len;
		
		len += lvl[i] - 1;
		
		for(int j:adj[i])
			lvl[j]--;

	}
	
	return cnt;
	
}



int main(){
	
	IO
	
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll cnt = SolveInc();
	//ll val = SolveDec();
	
	
	ll ans = cnt;
	
	for(int i=1;i<n;++i){
		cnt -= (n-i+1);
		for(int j:adj[i])
			if(j > i)
				cnt += (n-j+1);
		
		ans+=cnt;
	}

	
	
	cout<<ans<<endl;
	
	
}


