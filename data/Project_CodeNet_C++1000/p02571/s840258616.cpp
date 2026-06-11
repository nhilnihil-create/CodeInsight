#include <bits/stdc++.h>
using namespace std;


int main(){
	string s,t;
	int ans=1e5;
	cin>>s>>t;
	for(int i=0; i<s.size()-t.size()+1; i++){
		int cnt=0;
		string aux = s.substr(i, t.size());
		for(int j=0; j<t.size(); j++){
			if(aux[j]!=t[j])cnt++;
		}
		ans = min(ans, cnt);
	}
	cout<<ans<<endl;
}
