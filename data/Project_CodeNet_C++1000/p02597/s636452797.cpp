#include<bits/stdc++.h>
using namespace std;
int n,has,w,r;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='W') w++;
		else if(s[i]=='R') r++;
	}
	for(int i=0;i<s.size();i++)
	{
		if(r==0) break;
		if(s[i]=='W') has++,r--;
		else r--;
	}
	cout<<has<<endl;
}