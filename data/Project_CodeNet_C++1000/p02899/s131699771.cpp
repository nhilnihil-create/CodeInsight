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
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		cout<<v[i].second<<" ";
	}
	
	return 0;
}
