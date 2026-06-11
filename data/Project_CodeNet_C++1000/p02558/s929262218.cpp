#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main(){
	int n,q;
	cin >> n >> q;
	dsu d(n+1);
	for(int i = 0; i < q; i++){
		int t,a,b; cin >> t >> a >> b;
		if(t==0){
			d.merge(a,b);
		}else{
			cout << d.same(a,b) << "\n";
		}
	}
	
	return 0;
}
