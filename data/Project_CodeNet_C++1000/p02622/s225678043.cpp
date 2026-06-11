#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,ss;
	cin>>s>>ss;
	int size=s.size(),ans=0;
	for (int i=0;i<size;i++)
	{
		if (s[i]!=ss[i])ans++;
	}cout<<ans<<"\n";
}