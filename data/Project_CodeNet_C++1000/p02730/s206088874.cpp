#include<bits/stdc++.h>
using namespace std;
bool is_pel(string a){
	int len = a.length();
	for(int i=0; a[i]; i++){
		if(a[i]!=a[len-1-i]) return false;
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	int n = s.length();
	if(is_pel(s) && is_pel(s.substr(0,n/2)) && is_pel(s.substr(n/2+1)))
		cout<<"Yes";
	else cout<<"No";
}