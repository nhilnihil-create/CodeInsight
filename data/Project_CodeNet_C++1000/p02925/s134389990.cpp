#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	vector<queue<int>> a(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			int a0; cin>>a0;
			a.at(i).push(--a0);
		}
	}
	int ans{};
	vector<int> d(n);
	iota(d.begin(),d.end(),0);
	while(1){
		vector<bool> c(n);
		vector<int> e;
		for(int i=0; i<d.size(); i++){
			int j=d.at(i);
			if(a.at(j).empty()) continue;
			auto b = a.at(j).front();
			if(c.at(b)||c.at(j)) continue;
			if(a.at(b).front()==j){
				a.at(j).pop();
				a.at(b).pop();
				c.at(j)=1;
				c.at(b)=1;
				e.push_back(j);
				e.push_back(b);
			}
		}
		if(e.size()==0){
			bool flg{1};
			for(int i=0; i<n; i++){
				flg &= a.at(i).empty();
			}
			if(flg) break;
			else{
				cout << -1 << endl;
				return 0;
			}
		}
		ans++;
		d = e;
	}
	cout << ans << endl;
	
}
