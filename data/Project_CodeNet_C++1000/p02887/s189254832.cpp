#include <bits/stdc++.h>
using namespace std;
void nil()
{
	int n;
	cin>>n;
	string s, c="";
	cin>>s;
	c=c+s[0];
	for(int i=1;i<n;i++)
	{
		if(c.back()!=s[i])
		{
			c=c+s[i];
		}
	}
	cout<<c.size();
}
int main()
{
	#ifndef ONLINE_JUDGE

		freopen("input1.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif	
		nil();

}
