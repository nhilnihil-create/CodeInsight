#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	a=a+b[b.size()-1];
	
	if(a==b) cout<<"Yes\n";
	else     cout<<"No\n";
	
	return 0;
}