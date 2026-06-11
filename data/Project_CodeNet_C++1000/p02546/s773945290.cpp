#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int r=s.size()-1;
	cout<<s;
	if(s[r]=='s')
		cout<<"es";
	else
		cout<<"s";
	return 0;
}