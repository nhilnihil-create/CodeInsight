# include <iostream>
# include <string>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	string s;
	k=0;
	cin>>s;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
		{
			k=k+1;
			i=i+2;
		}
	}
	cout<<k;
} 