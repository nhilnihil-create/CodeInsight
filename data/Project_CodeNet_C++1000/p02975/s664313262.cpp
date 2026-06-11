#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> a(n);
	map<int,int> ct;
	for (int i=0; i<n; i++)
		cin>>a[i], ct[a[i]]++;
	if (ct[0]==n) {
		cout<<"Yes\n";
		return 0;
	}
	if(n%3) {
		cout<<"No\n";
		return 0;
	}
	map<int,vector<int>> mp;
	for (auto it : ct)
		mp[it.second].push_back(it.first);
	if(!mp[n/3].empty() && !mp[2*n/3].empty() && ct[0]==n/3) {
		cout<<"Yes\n";
		return 0;
	}
	if(mp[n/3].size()!=3) {
		cout<<"No\n";
		return 0;
	}
	int cur=mp[n/3][0]^mp[n/3][1]^mp[n/3][2];
	cout<<(cur?"No":"Yes")<<"\n";
	return 0;
}