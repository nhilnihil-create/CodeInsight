# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define ub upper_bound
# define lb lower_bound
# define all(x) x.begin(), x.end()
# define pqueue priority_queue
# define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
# define rep(i,n) for(int i=0;i<n;++i)
# define forn(i,n) for(int i=1;i<=n;++i)
using namespace std;

template<class T> void umin(T &a,T b){a=min(a,b);}
template<class T> void umax(T &a,T b){a=max(a,b);}

typedef long long ll;
typedef pair<int,int> pii;

const int dx[]={1,0,-1,0,-1,-1,1,1},dy[]={0,1,0,-1,-1,1,-1,1}; 
const int mod = 1e9+7;
const ll N = 2e5+5;

void solve(){
	int n;
	cin>>n;
	vector<double>a(n);
	rep(i,n)cin>>a[i];
	while(sz(a)>1){
		sort(all(a));
		double x=a[0],y=a[1];
		vector<double>v;
		for(int i=2;i<sz(a);i++){
			v.pb(a[i]);
		}
		v.pb((x+y)/2.0);
		a.clear();
		for(auto i:v){
			a.pb(i);
		}
	}
	printf("%.6f",a[0]);
}

int main(){
	Speed();
	int T=1; 
	//cin>>T;	
	while(T--)solve();
}
