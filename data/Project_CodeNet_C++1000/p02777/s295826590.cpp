#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int a,b;
	cin>>a>>b;
	string u;
	cin>>u;
	if(s.compare(u)==0) cout<<a-1<<" "<<b;
	else cout<<a<<" "<<b-1;
}