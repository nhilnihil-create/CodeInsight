#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

#include <atcoder/dsu>
using namespace atcoder;

int main(){
	int n,q;cin>>n>>q;
	dsu uf(n);
	rep(i,q){
		int t,u,v;cin>>t>>u>>v;
		if(t==0)uf.merge(u,v);
		else cout<<(uf.same(u,v)?1:0)<<endl;
	}
}