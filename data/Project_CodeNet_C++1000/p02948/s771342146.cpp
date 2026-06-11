#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,m; cin>>n>>m;
	vector<pair<int,int>> ab(n);
	for(int i=0; i<n; i++) {
		cin>>ab.at(i).first>>ab.at(i).second;
		ab.at(i).second*=-1;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> p,q;
	for(int i=0; i<n; i++){
		p.push(ab.at(i));
	}
	int sum{};
	for(int i=m-1; i>=0; i--){
		while(!p.empty()){
			auto t = p.top();
			if(t.first==m-i){
				p.pop();
				swap(t.first,t.second);
				q.push(t);
			}
			else break;
		}
		if(!q.empty()){
			auto t = q.top();
			sum += t.first;
			q.pop();
		}
	}
	cout << -sum << endl;
	
}
