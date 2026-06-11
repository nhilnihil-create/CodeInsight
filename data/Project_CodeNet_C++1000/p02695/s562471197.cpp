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
const ll N = 1e5+4;
int n,m,q,ans;
int a[55],b[55],c[55],d[55];
vector<int>v;

void calc(int x,int j){
		if(j==n-1){
			int res=0;
			rep(i,q){
				if(v[b[i]]-v[a[i]]==c[i])res+=d[i];
			}
			umax(ans,res);
			return;
		}
		for(int i=x;i<=m;i++){
			v.pb(i);
			calc(i,j+1);
			v.pop_back();
		}
}

void solve(){
	cin>>n>>m>>q;
	rep(i,q){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		--a[i],--b[i];
	}
	for(int i=1;i<=m;++i){
		v.pb(i);
		calc(i,0);
		v.pop_back();
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