#include<bits/stdc++.h>
using namespace std;




int main(){
	
	string s;
	cin>>s;
	int i;
	for(i=1;i<s.size();i+=2){
		if(s[i-1]!='h' || s[i]!='i'){
			cout<<"No";
			return 0;
		}
	}
	if(s.size()&1)cout<<"No";
	else
	cout<<"Yes";
	return 0;
	
}