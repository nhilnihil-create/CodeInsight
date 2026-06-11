#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans/2;

}
