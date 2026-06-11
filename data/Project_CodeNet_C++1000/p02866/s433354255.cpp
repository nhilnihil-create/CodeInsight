#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int mod=998244353;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	map<int,int> ct;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin>>a[i], ct[a[i]]++;
	if(ct[0]!=1) {
		cout<<0<<"\n";
		return 0;
	}
	ll ret=1;
	for (int i=1; i<n; i++)
		ret=(ret*ct[a[i]-1])%mod;
	cout<<ret<<"\n";
	return 0;
}