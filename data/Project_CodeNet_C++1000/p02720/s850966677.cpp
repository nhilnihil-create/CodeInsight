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
const int N = 2e6+5;

vector<ll>v;

void calc(ll x){
	if(x>=1e10)return;
	v.pb(x);
	if(x%10!=0)calc(x*10+x%10-1);
	if(x%10!=9)calc(x*10+x%10+1);
	calc(x*10+x%10);
}

void solve(){
	int k;
	cin>>k;
	for(ll i=1;i<=9;++i)calc(i);
	sort(all(v));
	cout<<v[k-1];
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}