#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	if(n%2) cout<<"No";
	else{
		int len = n/2;
		if(s.substr(0,len).compare(s.substr(len,len))==0) 
			cout<<"Yes";
		else cout<<"No";
	}
}