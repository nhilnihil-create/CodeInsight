#include<bits/stdc++.h>
#include<atcoder/fenwicktree>
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
	int n,m;
	cin>>n>>m;
	fenwick_tree<ll > fw(n);
	int q;
	ll a,b;
	rep(i,n){
		cin>>a;
		fw.add(i,a);
	}
	while(m--){
		cin>>q>>a>>b;
		if(q==0){
			fw.add(a,b);
		}
		else{
			cout<<fw.sum(a,b)<<'\n';
		}
	}

}