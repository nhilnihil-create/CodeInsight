#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0; i<(1<<n); i++){
		int x;
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(), v.end());
	int fir=v.back();
	vector<int>ne;
	ne.pb(fir);
	v.pop_back();
	multiset<int>s;
	for(auto u:v){
		s.insert(u);
	}
	
	while(1){
		if(s.empty()){
			cout<<"Yes";
			return 0;
		}
		sort(ne.begin(), ne.end());
		reverse(ne.begin(), ne.end());
		vector<int>ne2;
		for(auto u:ne){
			auto it=s.lower_bound(u);
			if(it==s.begin()){
				cout<<"No";
				return 0;
			}
			it--;
			ne2.pb((*it));
			s.erase(s.find((*it)));
		}
		for(auto u:ne2){
			ne.pb(u);
		}
	}
	
	return 0;
}