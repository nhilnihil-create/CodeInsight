#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	getline(cin,s);
	//string r;
	ll t=s.size();
		char a='D';
		char b='P';
	for(ll i=0;i<t;i++){
		if(s[i]=='P'&&s[i+1]=='?'){
			s.replace(i+1,1,"D");
		}
		else if(s[i]=='?'){
			if(s[i+1]=='?'){
				s.replace(i,1,"P");
				s.replace(i+1,1,"D");
			}
			else if(s[i+1]=='D'){
			 s.replace(i,1,"P");
			}
			else{
			s.replace(i,1,"D");
			}
		}
	}
	cout<<s;
	
	return 0;
}