#include<bits/stdc++.h>
using namespace std;

int num[100010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	sort(num+1,num+n+1);
	if (num[n]==0) { puts("Yes");return 0; }
	if (n%3) { puts("No");return 0; }
	for (int i=1;i<=n/3;i++) if (num[i]!=num[1]) { puts("No");return 0; }
	for (int i=1;i<=n/3;i++) if (num[n/3+i]!=num[n/3+1]) { puts("No");return 0; }
	for (int i=1;i<=n/3;i++) if (num[n/3*2+i]!=num[n]) { puts("No");return 0; }
	if (num[1]==(num[n/3+1]^num[n])) puts("Yes");
	else puts("No");
	return 0;
}