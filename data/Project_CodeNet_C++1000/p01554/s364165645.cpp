#include<iostream>
#include<map>
using namespace std;
map<string,bool>M;
main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;cin>>s;M[s]=1;
	}
	cin>>n;
	int a=1;
	for(int i=0;i<n;i++)
	{
		string s;cin>>s;
		if(M[s])
		{
			cout<<(a?"Opened by ":"Closed by ")<<s<<endl;
			a=!a;
		}
		else
		{
			cout<<"Unknown "<<s<<endl;
		}
	}
}

