#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
string s;
int main()
{
	int n;
	cin>>n;
	ios;
	cin>>s;
	int num=0,len=s.size();
	for(int i=0;i<len-2;++i)
	{
		if(s[i]!='A')continue;
		else
		{
			if(s[i+1]=='B'&&s[i+2]=='C')
			{
				num++;
			}
		}
	}
	cout<<num<<'\n';
}