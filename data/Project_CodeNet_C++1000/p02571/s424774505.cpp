#include <bits/stdc++.h>
using namespace std;
string s, t, x;
int i, j, mn=10000, l;
int main()
{
	cin >> s >> t;
	for (i=0; i<=s.size()-t.size(); i++)
	{
		for (j=i; j<=i+t.size(); j++)
		x+=s[j];
		for (j=0; j<t.size(); j++)
		if (t[j]!=x[j]) l++;
		if (l<mn) mn=l;
		l=0; x="";
	}
	cout<<mn;
	return 0;
}
