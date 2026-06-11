#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int hugs=0;
	int n=s.size()/2;
	for (int i=0; i<n; i++)
	{
		if (s[i]!=s[s.size()-i-1]) hugs++;
	}
	cout<<hugs<<endl;
	return 0;
}