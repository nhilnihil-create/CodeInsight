#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

int main(){
	int n,q;
	cin >> n >> q;
	fenwick_tree<long long> fw(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		fw.add(i,x);
	}
	for(int i = 0; i < q; i++){
		int t,a,b; cin >> t >> a >> b;
		if(t==0){
			fw.add(a,b);
		}else{
			cout << fw.sum(a,b) << "\n";
		}
	}
	return 0;
}
