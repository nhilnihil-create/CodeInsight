// F - Intervals on Tree
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int64_t E = 0, V = 1LL*n*(n+1)*(n+2)/6;
	for(int i=0; i<n-1; ++i){
		int u, v; cin>>u>>v;
		if(u > v) swap(u, v);
		E += 1LL*u*(n-v+1);
	}
	cout<< V-E <<endl;
}
