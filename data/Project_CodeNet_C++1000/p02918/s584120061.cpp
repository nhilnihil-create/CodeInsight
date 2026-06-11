#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int N,K,cur=0; string S; cin>>N>>K>>S;
	for (int i=1; i<N; i++)
		cur+=int(S[i]==S[i-1]);
	cout<<min(N-1,cur+2*K)<<"\n";
	return 0;
}