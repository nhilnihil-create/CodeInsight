#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<char> v;
	for(int i=0;i<s.size();i++)
	{
		v.push_back(s[i]);
	}
	while(v.size()!=0)
	{
		if(v[0]=='h'&&v[1]=='i')
		{
			v.erase(v.begin());
			v.erase(v.begin());
		}
		else
		{
			cout<<"No";return 0;
		}
	}
	cout<<"Yes";
}