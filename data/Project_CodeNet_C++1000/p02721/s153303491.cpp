#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
 
main() {
	int n, k, c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	vector<int>v;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='o'){
			v.pb(i);
		}
	}
	int last=-1e9;
	vector<int>beg;
	vector<int>las;
	for(int i=0; i<v.size(); i++){
		if(v[i]-last>c){
			beg.pb(v[i]);
			last=v[i];
		}
	}
	last=1e9;
	for(int i=v.size()-1; i>=0; i--){
		if(last-v[i]>c){
			las.pb(v[i]);
			last=v[i];
		}
	}
	if(beg.size()>k){
		return 0;
	}
	reverse(las.begin(), las.end());
	vector<int>ans;
	for(int i=0; i<k; i++){
		if(las[i]==beg[i]){
			ans.pb(beg[i]+1);
		}
	}
	for(auto u:ans){
		cout<<u<<endl;
	}
	return 0;
}