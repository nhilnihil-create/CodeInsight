#include "bits/stdc++.h"
using namespace std;

int main(){
	string s;
	int m;
	map<string,int> mp;
	while(cin>>s){
		mp[s]++;
		int asd=s.size();
		m=max(m,asd);
	}
	
	int x=0;
	
	for(auto &el:mp){
		if(x<el.second){
			x=el.second;
		}
	}
	
	for(auto &el:mp){
		if(x==el.second){
			cout<<el.first<<" ";
			break;
		}
	}
	
	for(auto &el:mp){
		if(m==el.first.size()){
			cout<<el.first<<endl;
		}
	}
	
	return 0;
}