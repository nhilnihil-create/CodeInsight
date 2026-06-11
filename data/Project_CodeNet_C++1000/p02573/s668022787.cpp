#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define int ll
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> g[1000001];
int vis[1000001];
int n,m;
vector<int> cur;
int cnt=1;

void dfs(int u){
	vis[u]=1;
	for(auto x:g[u]){
		if(!vis[x]){
			dfs(x);
			cnt++;
		}
	}
}

int32_t main(){
    
	scanf("%lld%lld",&n,&m);
	set<int> st;
	while(m--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		st.ins(x);
		st.ins(y);
		g[x].pb(y);
		g[y].pb(x);
	}

	int ans=INT_MIN;

	for(int i=0;i<n;++i){
		if(!vis[i]){
			dfs(i);
			ans=max(ans,cnt);
			cnt=1;
			
		}
	}
	
	printf("%lld\n",ans);

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}
