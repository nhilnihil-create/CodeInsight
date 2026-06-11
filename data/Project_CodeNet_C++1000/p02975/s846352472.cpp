#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
map<int,int> S;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) S[a[i]]++;
	if(S.size()>3) return puts("No"),0;
	if(S.size()==1)
	{
		if(S.begin()->first==0) puts("Yes");
		else puts("No");return 0;
	}
	if(n%3) return puts("No"),0;
	if(S.size()==2)
	{
		if(S.begin()->first==0&&S.begin()->second==n/3) puts("Yes");
		else puts("No");return 0;
	}
	if(S.size()==3)
	{
		int v=0;
		for(map<int,int>::iterator it=S.begin();it!=S.end();it++)
		{
			v^=it->first;
			if(it->second!=n/3) return puts("No"),0;
		}
		if(v) puts("No");else puts("Yes");return 0;
	}
}
