#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({y,x});
	}
	
	sort(v.begin(),v.end());
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt += v[i].second;
		if(cnt > v[i].first){
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"Yes";
	
	return 0;
}
