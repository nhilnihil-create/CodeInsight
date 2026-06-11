#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

ll lcm(ll x, ll y) {
	return x/__gcd(x,y)*y;
}

ll eval(ll x) {
	ll ret=0;
	while(x%2==0)
		x>>=1, ret++;
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,M; cin>>N>>M;
	vector<int> a(N);
	set<ll> st;
	for (int i=0; i<N; i++) {
		cin>>a[i], a[i]>>=1;
		st.insert(eval(a[i]));
	}
	if(st.size()>1) {
		cout<<"0\n";
		return 0;
	}

	ll l=1;
	for (int i=0; i<N; i++) {
		l=lcm(l,a[i]);
		if(l>M) {
			cout<<"0\n";
			return 0;
		}
	}
	cout<<(M/l+1)/2<<"\n";
	return 0;
}