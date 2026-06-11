#include<iostream>
using namespace std;
int main()
{
	int n,i,d;
	string s;
	cin>>n>>s;
 
	if(n%2!=0)
		cout<<"No"<<endl;
	else
	{
		d = n/2;
		bool ok = true;
 
		for(i=0;i<d;i++)
		{
			if(s[i]!=s[i+d])
			{
				ok = false;
				break;
			}
		}
 
		if(ok)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}