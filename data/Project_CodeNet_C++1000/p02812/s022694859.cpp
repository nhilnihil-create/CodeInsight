#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[105];
int main()
{
	int n;
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
		{
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 