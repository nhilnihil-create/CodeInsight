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
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	pqueue<int,vector<int>,greater<int>>A,B;
	pqueue<int>C;
	for(int i=0;i<a;++i){
		int xx;
		cin>>xx;
		A.push(xx);
	}
	for(int i=0;i<b;++i){
		int xx;
		cin>>xx;
		B.push(xx);
	}
	for(int i=0;i<c;++i){
		int xx;
		cin>>xx;
		C.push(xx);
	}
	while(sz(A)>x){
		A.pop();
	}
	while(sz(B)>y){
		B.pop();
	}
	while(!C.empty()){
		int xx=C.top();
		C.pop();
		if(A.top()<=B.top()){
			if(A.top()<xx){
				A.pop();
				A.push(xx);
			}
			else break;
		}
		else{
			if(B.top()<xx){
				B.pop();
				B.push(xx);
			}
			else break;
		}
	}
	ll ans=0;
	while(!A.empty()){
		ans+=A.top();
		A.pop();
	}
	while(!B.empty()){
		ans+=B.top();
		B.pop();
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