#include<cstdio>
#include<map>
using namespace std;
map<pair<int,int>,int>M;
char buf[2000];
int sz;
int N;
int x[50],y[50];
main()
{
	fread(buf,1,2000,stdin);
	for(;;)
	{
		char k=buf[sz++];
		if(k<'0')break;
		N=N*10+k-'0';
	}
	for(int i=0;i<N;i++)
	{
		bool neg=buf[sz]=='-'?++sz:false;
		for(;;)
		{
			char k=buf[sz++];
			if(k<'0')break;
			x[i]=x[i]*10+k-'0';
		}
		if(neg)x[i]=-x[i];
		neg=buf[sz]=='-'?++sz:false;
		for(;;)
		{
			char k=buf[sz++];
			if(k<'0')break;
			y[i]=y[i]*10+k-'0';
		}
		if(neg)y[i]=-y[i];
	}
	int ans=N;
	M[make_pair(0,0)]=-N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int now=N-++M[make_pair(x[i]-x[j],y[i]-y[j])];
			if(ans>now)ans=now;
		}
	}
	printf("%d\n",ans);
}