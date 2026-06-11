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
const ll N = 2e5+4;

ll n,m,k,a[N],prefA[N],prefB[N],b[N];

bool check(ll x){
	for(int i=0;i<=n;++i){
		ll j=k;
		bool ok=0;
		if(i){
			if(prefA[i]<=k){
				j-=prefA[i];
				ok=1;
			}
		}
		ll l=1,r=m,ans=0;
		if(j>=prefB[1]){
			while(l<=r){
				ll m=(l+r)/2;
				if(prefB[m]<=j){
					ans=m;
					l=m+1;
				}
				else r=m-1;
			}		
		}
		if(ans+(ok?i:0)>=x)return 1;
	}
	return 0;
}

void solve(){
	cin>>n>>m>>k;
	forn(i,n){
		cin>>a[i];
		prefA[i]=prefA[i-1]+a[i];
	}
	forn(i,m){
		cin>>b[i];
		prefB[i]=prefB[i-1]+b[i];
	}
	ll l=0,r=n+m,ans=0;
	while(l<=r){
		ll m=(l+r)/2;
		if(check(m)){
			ans=m;
			l=m+1;
		}
		else r=m-1;
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