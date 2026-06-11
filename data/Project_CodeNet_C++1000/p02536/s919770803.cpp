// C - Connect Cities
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main(){
	int n, m; cin>>n>>m;
	dsu d(n);
	int ans = n - 1;
	while(m--){
		int a, b; cin>>a>>b; --a,--b;
		if(!d.same(a, b)){
			d.merge(a, b);
			ans--;
		}
	}
	cout<< ans <<endl;
}
