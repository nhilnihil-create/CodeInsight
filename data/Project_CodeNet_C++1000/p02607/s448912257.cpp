#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=105;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x*t;
}
int arr[N];
int main()
{
	register int n=read();
	for(register int i=0;i<n;i++)
		arr[i]=read();
	register int cnt=0;
	for(register int i=0;i<n;i++)
		if((i+1)%2!=0&&arr[i]%2!=0) cnt++;
	printf("%d\n",cnt);
	return 0;
}