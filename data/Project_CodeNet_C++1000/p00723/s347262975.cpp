#include<iostream>
#include<set>
#include<algorithm>
#define G a.insert(A+B);a.insert(B+A);
using namespace std;
string s;
int n;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		set<string>a;
		for(int i=1;i<s.size();i++)
		{
			string A=s.substr(0,i),B=s.substr(i);
			G
			reverse(B.begin(),B.end());
			G
			reverse(A.begin(),A.end());
			G
			reverse(B.begin(),B.end());
			G
		}
		cout<<a.size()<<endl;
	}
}


