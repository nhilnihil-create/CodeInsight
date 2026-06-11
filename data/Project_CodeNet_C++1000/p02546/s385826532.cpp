#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	if(s.back()=='s')
	{
		s+="es";
	}
	else
	{
		s+="s";
	}
	cout<<s;

	return 0;
}