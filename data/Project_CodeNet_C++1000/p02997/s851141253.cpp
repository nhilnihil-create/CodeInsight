#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,K; cin>>N>>K;
	if (K>(N-1)*(N-2)/2) {
		cout<<-1<<"\n";
		return 0;
	}
	int ret=N*(N-1)/2-K;
	cout<<ret<<"\n";
	for (int i=1; i<N&&ret; i++)
		for (int j=i+1; j<=N&&ret; j++,ret--)
			cout<<i<<" "<<j<<"\n";
	return 0;
}