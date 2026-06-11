#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	string s,t; cin>>s>>t;
	int n = s.size();
	vector<vector<int>> a(n+1,vector<int>(26,-1));
	for(int i=n-1; i>=0; i--){
		a.at(i) = a.at(i+1);
		a.at(i).at(s.at(i)-'a') = i+1;
	}
	ll cnt{},now{};
	for(auto i:t){
		if(a.at(0).at(i-'a')==-1){
			cout << -1 << endl;
			return 0;
		}
		if(a.at(now).at(i-'a')==-1){
			cnt++; now=0;
		}
		now = a.at(now).at(i-'a');
	}
	cout << cnt*n+now << endl;
	
}