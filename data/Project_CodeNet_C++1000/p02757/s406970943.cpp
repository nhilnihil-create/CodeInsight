#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline LL read()
{
	LL kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
LL n,mod,len,asd=0;
char ss[400022];
LL cou[200022],cun[200022];
int main()
{
	n=read();mod=read();
	scanf("%s",ss);len=strlen(ss);
	if(mod==2)
	{
		for(int i=0;i<len;++i)
		{
			if(!((ss[i]-'0')&1))asd+=i+1;
		}
		printf("%lld\n",asd);
		return 0;
	}
	if(mod==5)
	{
		for(int i=0;i<len;++i)
		{
			if(((ss[i]-'0')==0)||((ss[i]-'0')==5))asd+=i+1;
		}
		printf("%lld\n",asd);
		return 0;
	}
	reverse(ss,ss+len);
	LL bas=1;
	LL kk=0;
	for(int i=0;i<len;++i)
	{
		kk=(kk+(ss[i]-'0')*bas)%mod;
		asd+=cou[kk]++;
		if(kk==0)asd++;
		bas=(bas*10)%mod;
	}
	printf("%lld\n",asd);
}//