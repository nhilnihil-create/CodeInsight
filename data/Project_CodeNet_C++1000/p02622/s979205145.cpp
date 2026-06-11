#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
	string s, a;
	cin>>s>>a;
	ll z = 0;
	for(size_t i = 0; i<s.size(); i++)
	{
		if(s[i]!=a[i])
		{
			z++;
		}
	}
	cout<<z<<endl;
	return 0;
}