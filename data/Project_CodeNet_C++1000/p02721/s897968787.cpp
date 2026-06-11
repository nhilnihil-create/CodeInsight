#include<bits/stdc++.h>
using namespace std;
int n,k,c,a,b;
vector<int>v1,v2;
string s;
int main()
{
	cin>>n>>k>>c>>s;
	a=-1e9,b=1e9;
	for(int i=0;i<n;++i)
	{
		 if(s[i]=='o'&&a+c<i)
		 {
		 	a=i;
		 	v1.push_back(i);
		 }
		 if(v1.size()==k) break;
	}
	for(int i=n-1;i>=0;--i)
	{
		if(s[i]=='o'&&b>=c)
		{
			b=0;
			v2.push_back(i);
		}
		else ++b;
		if(v2.size()==k) break;
	}
	reverse(v2.begin(),v2.end());
	for(int i=0;i<k;++i)
	 if(v1[i]==v2[i])
	  cout<<v1[i]+1<<endl;
	return 0;
}