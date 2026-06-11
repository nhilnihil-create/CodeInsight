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

bool check(ll x,vector<ll>&a,ll n){
	vector<ll>b=a,ans(n);
	ans[0]=x;
	b[0]-=ans[0]/2;
	b[n-1]-=ans[0]/2;	
	for(ll i=1;i<n;i++){
		ans[i]=b[i-1]*2;
		b[i]-=ans[i]/2;
		b[i-1]-=ans[i]/2;
	}
	bool ok=1;
	for(ll i=0;i<n;i++){
		if(b[i]){
			ok=0;
			break;	
			}
	}
	return ok;
}

void printAns(ll x,vector<ll>&a,ll n){
	vector<ll>b=a,ans(n);
	ans[0]=x;
	b[0]-=ans[0]/2;
	b[n-1]-=ans[0]/2;	
	for(ll i=1;i<n;i++){
		ans[i]=b[i-1]*2;
		b[i]-=ans[i]/2;
		b[i-1]-=ans[i]/2;
	}
	for(ll i=0;i<n;++i){
		cout<<ans[i]<<' ';
	}
}


void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n);
	ll x=0;
	for(ll i=0;i<n;++i){
		cin>>a[i];
		if(i%2)x-=a[i];
		else x+=a[i];
	}
	printAns(x,a,n);
	
}

int main(){
	Speed();
	int T=1;
	//cin>>T;
	while(T--)solve();
}

