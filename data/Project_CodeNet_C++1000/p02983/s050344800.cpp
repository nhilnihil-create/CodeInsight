#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

#define rep(i,n) for(int i=0;i<n;++i)
#define Rep(i,a,n) for(int i=a;i<=n;++i)
#define Speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mset multiset
#define pqueue priority_queue
#define umap unordered_map
 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const double PI=acos(-1),eps=1e-9;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
const int N=3e5+5,mod=2019,inf=1e9;

void solve(){
	ll l,r;
	cin>>l>>r;
	if(r-l+1>=5000){
		cout<<0;
		return;
	}
	ll ans=2019;
	for(ll i=l;i<=r;i++){
		for(ll j=i+1;j<=r;j++){
			ll x=i*j;
			ans=min(ans,x%mod);
		}
	}
	cout<<ans;
}

int main(){
	Speed();
	int T=1;
	//cin>>T;
	while(T--)solve();
}

