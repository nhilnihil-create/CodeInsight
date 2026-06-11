#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;cin>>N;
	string s;cin>>s;
	int size=s.length();
	string ans="";
	for(int i=0;i<size;++i){
		char c=s[i]+N;
		if(c-'A'>=26){
		  	int shift = c-'Z';
		  	c='A'+shift-1;
		}
		ans.push_back(c);
	}
	cout<<ans<<"\n";
}