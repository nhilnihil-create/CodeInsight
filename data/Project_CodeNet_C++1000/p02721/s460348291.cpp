#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s;
int n,k,c;
int l[N],r[N];
int main()
{
	cin>>n>>k>>c>>s;
	int i=1,kk=1;
	while(kk<=k)
	{
		if(s[i-1]=='o')
		{
			l[kk++]=i;
			i+=c;
		}
		i++;
	}
	i=n,kk=k;
	while(kk)
	{
		if(s[i-1]=='o')
		{
			r[kk--]=i;
			i-=c;
		}
		i--;
	}
	for(i=1;i<=k;i++)
	{
		if(l[i]==r[i])cout<<l[i]<<endl;
	}
return 0;
}
