//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	string s,t;
	cin>>n>>s>>t;
	
	string ans = "";
	for(int i=0;i<n;i++){
		ans += s[i];
		ans += t[i];
	}
	cout<<ans;
	
	return 0;
}
