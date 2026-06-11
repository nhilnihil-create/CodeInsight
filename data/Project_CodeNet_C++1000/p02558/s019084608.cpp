#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,a,b) for(int i=a;i<b;i++)
typedef vector<int > vi;
typedef vector<pair<int, int > > vp;
int main(){
	//m containers ai matchboxes bi matches
	//burglar bag n matchboes
	int n;
	cin>>n;
	dsu d(n);
	int m;
	cin>>m;
	int q,u,v,ur;
	while(m--){
		cin>>q>>u>>v;
		if(q==1){
			cout<<d.same(u,v)<<'\n';
		}
		else{
			ur = d.merge(u,v);
		}
	}

}