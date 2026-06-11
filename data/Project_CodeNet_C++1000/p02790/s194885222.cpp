#include "bits/stdc++.h"
using namespace std;

int a,b;

int main()
{
	cin>>a>>b;

	string sa=string(b, '0' + a);
	string sb=string(a, '0' + b);

	if(sa.size() != sb.size())
	{
		if(sa.size()>sb.size()) cout<<sa;
		else cout<<sb;
	}
	else
	{
		if(sa>sb) cout<<sa;
		else cout<<sb;
	}
}