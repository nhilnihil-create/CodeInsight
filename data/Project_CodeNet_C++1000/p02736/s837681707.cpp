#include<bits/stdc++.h>
using namespace std;
int b[3],n;
int main()
{
	memset(b,0,sizeof(b));
	int f=0;
	string a;
	cin>>n>>a;
	int i=0;
	while(i<n) 
	{
		--a[i];
		if(a[i]=='1') f=1;
		b[a[i]-'0']+=(((n-1)&i)==i);
		++i;
	}
	if(b[1]&1) puts("1");
	else if((!f)&&(b[2]&1)) puts("2");
	else puts("0");
	return 0;
}