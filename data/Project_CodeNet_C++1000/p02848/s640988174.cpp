//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	string s;
	cin>>n>>s;
	
	for(int i=0;i<(int)s.size();i++){
		int t = s[i]-'A';
		t += n;
		t %= 26;
		s[i] = 'A' + t;
	}
	
	cout<<s;
	
	return 0;
}
