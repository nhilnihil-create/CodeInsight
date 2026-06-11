#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	multiset<int> s;
	for(int i=0; i<(1<<n); ++i){
		int a; cin >> a;
		s.insert(a);
	}
	vector<int> v;
	v.push_back(*s.rbegin());
	s.erase(v[0]);
	for(int i=0; i<n; ++i){
		int m = v.size();
		for(int j=0; j<m; ++j){
			auto it = s.lower_bound(v[j]);
			if(it == s.begin()){
				cout << "No\n";
				return 0;
			}else{
				--it;
				v.push_back(*it);
				s.erase(it);
			}
		}
	}
	cout << "Yes\n";
}