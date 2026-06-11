#include<bits/stdc++.h>
using namespace std;
#define int long long

main(){
	string s; cin>>s;
	int sum = 0;
	for(int i=0; i<s.length(); i++) sum += s[i]-'0';
	if(sum%9==0) cout<<"Yes";
	else cout<<"No";
}