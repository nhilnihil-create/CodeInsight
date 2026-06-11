#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	string s;
	cin>>s;
	s.push_back('@');
	int ans=0;
	for(int i=0;i<s.size()-1;++i){
		if(s[i]!=s[i+1]) ++ans;
	}
	cout<<ans;
	return 0;
}
