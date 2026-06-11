#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	map<int, int> mp;
	for(int i = 0; i < (1<<n); i++){
		int x; cin>>x;
		mp[x]++;
	}
	vector<int> vec;
	int val = (*mp.rbegin()).first;
	vec.push_back(val);
	mp[val]--; if(!mp[val])mp.erase(val);
	for(int i = 0; i < n; i++){
		vector<int> nvec;
		for(auto x : vec){
			auto it = mp.lower_bound(x);
			if(it == mp.begin()){
				cout<<"No\n";
				exit(0);
			}
			it--; int val = it->first;
			nvec.push_back(x);
			nvec.push_back(val);
			mp[val]--; if(!mp[val])mp.erase(val);
		}
		sort(nvec.begin(), nvec.end());
		vec = nvec;
	}
	cout<<"Yes\n";

	return 0;
}