#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	char s[105];
	int l,j,x=0,t;
	cin>>t;
	cin>>s;
	j=t/2;
	if(t%2!=0)
		cout<<"No"<<endl;
	else
	{
		for(int i=0;i<t/2;i++,j++)
		{
			if(s[i]!=s[j])
			{
				x=1;
				break;
			}		
		}
		if(x)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}