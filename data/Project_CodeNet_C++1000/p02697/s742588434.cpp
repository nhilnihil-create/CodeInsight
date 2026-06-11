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
int main()
{
	LL a,b,now=1;a=read();b=read();
	LL fi=1,se=1+b;
	for(int i=1;i<=b;++i)
	{
		if(fi>=se)
		{
			fi=b+2;
			se=2*b+1;
		}
		printf("%lld %lld\n",fi,se);
		fi++;se--;
	}
}