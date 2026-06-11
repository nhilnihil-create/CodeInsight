#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,K,C; cin>>N>>K>>C;
	string S; cin>>S; S='@'+S;
	vector<int> L(N,INT_MAX), R(N,INT_MAX);
	int cur=0;
	for (int i=1; i<=N; i++) {
		if(S[i]=='o') {
			L[++cur]=i;
			if(cur>=K) break;
			i+=C;
		}
	}
	cur=K;
	for (int i=N; i>=1; i--) {
		if(S[i]=='o') {
			R[cur--]=i;
			if(cur<=0) break;
			i-=C;
		}
	}
	ll ret=0;
	for (int i=1; i<=K; i++)
		if(L[i]==R[i])
			cout<<L[i]<<"\n";
	return 0;
}