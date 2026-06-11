#include<bits/stdc++.h>
using namespace std;
int k;
set<string> s;
vector<string> v;
void dfs(string x){
	if(s.find(x)!=s.end())return ;
	s.insert(x);
	v.push_back(x);
	if(x.size()==10)return ;
	if(x[x.size()-1]=='0')dfs(x+'1');
	else if(x[x.size()-1]=='9')dfs(x+'8');
	else{
		dfs(x+(char)(x[x.size()-1]-1));
		dfs(x+(char)(x[x.size()-1]+1));
	}
	dfs(x+x[x.size()-1]);
}
inline bool cmp(string k1,string k2){
	if(k1.size()<k2.size())return true;
	else if(k1.size()>k2.size())return false;
	else if(k1<=k2)return true;
	else return false;
}
int main(){
	cin>>k;
	for(char c='1';c<='9';c++){
		string t="";
		t+=c;
		dfs(t);
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v[k-1]<<endl;
	return 0;
}