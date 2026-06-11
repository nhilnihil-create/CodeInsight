#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	map<char,int> ct;
	int mx=0;
	for (const char ch : s)
		ct[ch]++,mx=max(mx,ct[ch]);
	cout<<(ct.size()==2&&mx==2?"Yes":"No")<<endl;
	return 0;
}
