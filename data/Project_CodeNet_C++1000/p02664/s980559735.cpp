#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,a="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			a+='D';
		}
		else
		a+=s[i];
	}
	cout<<a<<endl;
	return 0;
}
