#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int mod=1e9+7;
const int mx=2077;

ll binom[mx][mx];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	for (int i=0; i<mx; i++) {
		binom[i][0]=binom[i][i]=1;
		for (int j=1; j<i; j++)
			binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%mod;
	}
	int N,K; cin>>N>>K;
	int x=N-K+1;
	for (int i=1; i<=K; i++) {
		if(i>x) cout<<0<<"\n";
		else cout<<(binom[N-K+1][i]*binom[K-1][K-i])%mod<<"\n";
	}
	return 0;
}