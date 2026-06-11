#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define $(x) cout<<">>"<<#x<<":"<<x<<"\n"
const double eps = 1e-9;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int res=0;
	int count=0;
	for(int i=0;i<3;++i)
	{
		if(s[i]=='R')
			++count;
		else
		{
			if(count>res)
				res=count;
			count=0;

		}
	}
	if(count>res)
		res=count;
	cout<<res;
	return 0;
}
