#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		v.push_back(make_pair(a,i));
	}
	sort(v.begin(), v.end(), comp);
	int mx = v.back().first;
	for(int i=0; i<n; i++){
		if(i!=v.back().second){
			cout << mx;
		}
		else{
			cout << v[v.size()-2].first;
		}
		cout << endl;
	}
	return 0;
}