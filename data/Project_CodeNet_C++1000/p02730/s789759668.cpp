#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	string t=s;
	reverse(s.begin(),s.end());
	if(t!=s)
	 cout<<"No";
	else
	{
		string s1=s.substr(0,n/2);
		string s2=t.substr(0,n/2);
		string t1=s1,t2=s2;
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(),s2.end());
		if(t1==s1 && t2==s2)
		 cout<<"Yes";
		else
		 cout<<"No";
	}
	return 0;
}