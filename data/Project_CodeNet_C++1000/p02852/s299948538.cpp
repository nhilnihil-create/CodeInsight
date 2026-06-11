#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,m; cin>>n>>m;
	string s; cin>>s;
	int now = n;
	vector<int> ans;
	while(1){
		int to{now};
		for(int i=1; i<=m; i++){
			if(s.at(now-i)=='0'){
				to = now-i;
				if(to==0) break;
			}
		}
		ans.push_back(now-to);
		if(to == now) {
			cout << -1 << endl;
			return 0;
		}
		if(to == 0) break;
		now = to;
	}
	for(auto it=ans.rbegin(); it!=ans.rend(); it++) cout << *it << (it!=ans.rend()-1?' ':'\n');
	cout << flush;
	
}

