#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s,t;
	cin>>s>>t;
	bool ac = true;
	for(int i=0; i<s.size();i++){
		if(s[i]!=t[i])ac = false;
	}
	if(ac)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
