#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
string s,h;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s>>h;
	for(b=0; b<s.size(); b++){
		if(s[b]==h[b]) c++;
	}
	cout<<c;
	return 0;
}