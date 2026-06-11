#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	char ch[105];
	int k;
	cin>>k>>ch;
	int i,len;
	len=strlen(ch);
	for(i=0;i<k&&i<len;++i)
	{
		putchar(ch[i]);
	}
	if(i==k&&i<len)
	puts("...");
	else
	putchar('\n');
	return 0;
}