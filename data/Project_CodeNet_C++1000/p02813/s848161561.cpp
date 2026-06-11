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

template<class T> void umin(T &a, T b) { a = min(a, b); }
template<class T> void umax(T &a, T b) { a = max(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 2e5+5;

void solve(){
	int n;
	cin>>n;
	int a[n],b[n],v[n];
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];
	rep(i,n)v[i]=i+1;
	int aa=0,bb=0;
	int j=0;
	do{	bool ok=1,bok=1;
		j++;
		rep(i,n){
			if(v[i]!=a[i])ok=0;
			if(v[i]!=b[i])bok=0;
		}
		if(ok)aa=j;
		if(bok)bb=j;
	}
	while(next_permutation(v,v+n));
	cout<<abs(aa-bb);
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)
		solve();
	return 0;
}