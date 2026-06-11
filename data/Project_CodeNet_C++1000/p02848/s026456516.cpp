#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	string s; 
	cin>>s;
	for(auto& c:s)
	{
		int x=(c-'A'+n)%26;
		c='A'+x;
	}
	cout<<s;
}