#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	string s,t;
	cin>>s>>t;
	t.pop_back();
	if(s==t) cout<<"Yes";
	else cout<<"No";
	return 0;
}
