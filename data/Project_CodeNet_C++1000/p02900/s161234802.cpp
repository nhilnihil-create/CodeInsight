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
const ll N = 2e6+5;

//ll prime[N];

bool isprime(ll x){
	if(x<=2)return true;
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

void solve(){
	ll a,b;
	// rep(i,N+1)prime[i]=1;
	// for(int i=2;i<=N;++i){
	// 	for(int j=i+i;j<=N;j+=i){
	// 		prime[j]=0;
	// 	}
	// }
	cin>>a>>b;
	ll g=__gcd(a,b);
	vector<ll>v;
	for(ll i=1;i*i<=g;++i){
		if(g%i==0){
			v.pb(i);
			if(g/i!=i)v.pb(g/i);
		}
	}
	ll cnt=0;
	for(auto i:v){
		if(isprime(i))cnt++;
	}
	cout<<cnt;
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}