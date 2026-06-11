#include<cstdio>
#include<algorithm>
#define RI register int
#define CI const int&
using namespace std;
const int N=1e6+5;
int n,b[N],ret; char a[N]; bool one;
int main()
{
	RI i,j; for (scanf("%d%s",&n,a),--n,i=0;i<n;++i) b[i]=abs(a[i]-a[i+1]);
	for (i=0;i<n;++i) if (b[i]==1) one=1;
	if (!one) { for (i=0;i<n;++i) if (b[i]==2) b[i]=1; }
	else for (i=0;i<n;++i) b[i]%=2;
	//for (i=0;i<n;++i) printf("%d",b[i]);
	for (i=0;i<n;++i) if (((n-1)^i)==n-1-i) ret^=b[i];
	return printf("%d",ret*(one?1:2)),0;
}