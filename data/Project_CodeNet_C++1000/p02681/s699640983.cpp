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
	int flag=1;
	for(int i=0;s[i]!='\0';++i){
		if(s[i]!=t[i]){
			cout<<"No";
			flag=0;
			break;
		}
	}
	if(flag) cout<<"Yes";
	return 0;
}
