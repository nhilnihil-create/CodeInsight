#include <bits/stdc++.h>

using namespace std;

set<int>g[26];

int main(){
	string s,t;
	cin>>s>>t;
	for(int i=0;i<(int)s.size();++i){
		g[s[i]-'a'].insert(i+1);
	}
	long long cur=0,ans=0;
	for(int i=0;i<(int)t.size();++i){
		if((int)g[t[i]-'a'].size()==0){
			cout<<-1;
			return 0;
		}
		if(g[t[i]-'a'].upper_bound(cur)!=g[t[i]-'a'].end()){
			cur=*g[t[i]-'a'].upper_bound(cur);
		}
		else{
			cur=*g[t[i]-'a'].upper_bound(0);
			ans+=(int)s.size();
		}
		//cerr<<cur<<' '<<ans<<'\n';
	}
	cout<<ans+cur;
}