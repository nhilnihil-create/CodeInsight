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
const int N=3e5+5,mod=1e9+7,inf=1e9;

void solve(){
	int n,d;
	cin>>n>>d;
	int x[n][d];
	for(int i=0;i<n;++i){
		for(int j=0;j<d;j++){
			cin>>x[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<n;++i){
		for(int k=0;k<i;k++){
			ll s=0;
			for(int j=0;j<d;j++){
				s+=abs(x[k][j]-x[i][j])*abs(x[k][j]-x[i][j]);
			}
			ll b=sqrt(s);
			if(b*b==s){
				ans++;
			}
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

