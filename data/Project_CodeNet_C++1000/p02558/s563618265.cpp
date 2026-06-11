#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, q;
	cin>>n>>q;

	dsu d(n);
	rep(_, q){
		int t, u, v;
		cin>>t>>u>>v;

		if(t==0) d.merge(u, v);
		else cout<<d.same(u, v)<<endl;
	}
	return 0;
}
