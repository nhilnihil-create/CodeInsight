# include <iostream>
# include <string>
using namespace std;
int main()
{
	int p,n;
	p=0;
	string s; 
	cin>>s;
	n=s.size();
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!=s[n-1-i])
		{
			p=1;
		}
		if(i<(s.size()-1)/2)
		{
		if(s[i]!=s[(s.size()-1)/2-1-i])
		{
			p=1;
		}
	}
	if(i>=(s.size()+3)/2-1)
	{
	if(s[i]!=s[n-1-i])
	{
	p=1;	
	}
}
	}
	if(p==1)
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
}