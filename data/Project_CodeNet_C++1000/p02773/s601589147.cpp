#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>::iterator it;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		it = m.find(s);
		if(it!=m.end()) it->second+=1;
		else m.insert(make_pair(s,1));		
	}
	int maxnum = 0;
	for(it = m.begin(); it!=m.end(); it++){
		maxnum = max(maxnum,it->second);
	}
	vector<string> ret;
	for(it = m.begin(); it!=m.end(); it++){
		if(it->second==maxnum) ret.push_back(it->first);
	}
	sort(ret.begin(),ret.end());
	for(int i=0; i<ret.size(); i++) cout<<ret[i]<<'\n';
}