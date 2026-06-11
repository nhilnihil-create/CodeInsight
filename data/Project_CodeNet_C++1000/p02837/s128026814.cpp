# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define mset multiset
# define umap unordered_map
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
# define lr(i,l,r) for(int i=l;(l>r?i>=r:i<=r);(l>r?--i:++i))

using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 2e5+5;


void solve(){
	int n;
	cin>>n;
	int a[n];
	int x[n][15],y[n][15];
	rep(i,n){
		cin>>a[i];
		rep(j,a[i]){
			cin>>x[i][j]>>y[i][j];
			--x[i][j];
		}	
	}
	int ans=0;
	for(int mask=0;mask<(1<<n);++mask){
		int c[n];
		int res=0;
		rep(i,n){
			if(mask&(1<<i))c[i]=1,res++;
			else c[i]=0;
		}
		//cerr<<"res is"<<res<<'\n';
		bool ok=1;
		rep(i,n){
			if(c[i]){
				rep(j,a[i]){
					if(c[x[i][j]]!=y[i][j])ok=0;
				}
			}
		}
		if(ok)umax(ans,res);
	}
	cout<<ans;
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}