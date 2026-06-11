// C - Connect Cities
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main(){
	int n, m; cin>>n>>m;
	dsu d(n);
	while(m--){
		int a, b; cin>>a>>b;
		d.merge(a-1, b-1);
	}
	cout<< d.groups().size() - 1 <<endl;
}
