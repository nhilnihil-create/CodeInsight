#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mInt = modint998244353;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000



int main(){
	int N,Q;
	cin>>N>>Q;
	
	fenwick_tree<long long> F(N);
	
	vector<long long> a(N);
	rep(i,N){
		cin>>a[i];
		F.add(i,a[i]);
	}	
	
	rep(i,Q){
		int t;
		cin>>t;
		
		if(t==0){
			int p,x;
			cin>>p>>x;
			F.add(p,x);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<F.sum(l,r)<<endl;
		}
	}
	
    return 0;
}