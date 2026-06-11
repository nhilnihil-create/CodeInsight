#include <bits/stdc++.h>
#include "atcoder/all"
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using namespace std;
using namespace atcoder;
#define all(a) a.begin(),a.end()
typedef long long ll;
#define vi vector<ll>
typedef pair<ll,ll>P;
const ll inf=1ll<<61;

signed main(){
	int n,q;cin>>n>>q;
	dsu d(n);

	rep(i,q){
		int t,u,v;cin>>t>>u>>v;
		if(t==0){
			d.merge(u,v);
		}
		else{
			if(d.same(u,v))cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
}