#include<stdio.h>
#include<bitset>
int main()
{
	std::bitset<246913> p;
	int i,j,s=p.size();
	p.set();
	p[0]=p[1]=0;
	for(i=2;i*i<s;++i)if(p[i])for(j=i*i;j<s;j+=i)p[j]=0;
	while(s=!scanf("%d",&j),j)
	{
		for(i=j+1;i<=j*2;++i)if(p[i])++s;
		printf("%d\n",s);
	}
	return 0;
}