//B Ed 31
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	string s;
	int flag=0;
	cin>>s;
	for(int i=0;i<3;i++)
	{
		if(s[i+1]==s[i])
		{
			flag=1;
			break;
		}

	}
	if(flag)
		cout<<"Bad";
	else
		cout<<"Good";
}