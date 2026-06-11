#include<bits/stdc++.h>
using namespace std;
int n,g,p,w,r,i;
string s,t;
int main(){
	cin>>n>>s;
	for(i=0;i<n;i++)s[i]=='W'?p++:g++;
	for(i=0;i<g;i++)t+="R";
	for(i=0;i<p;i++)t+="W";
	for(i=0;i<n;i++){
		if(s[i]=='R'&&t[i]=='W')r++;
		else if(s[i]=='W'&&t[i]=='R')w++;
	}
	cout<<min(w,r)+abs(w-r);
	return 0;
}