# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <string>
# include <cstring>
# include <iomanip>
# include <functional>
# include <numeric>
# include <map>
# include <cstdlib>
# include <queue>
# include <cctype>
using namespace std;
template <class code>inline code read(const code &a)
{
    code x=0;short w=0;char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}
typedef long long ll;
const int N=2e5+5;
char s[N];
int l[N],r[N];
int main ()
{
	memset (l,-1,sizeof (l));
	memset (r,-1,sizeof (r));
	int n=read (n),k=read (k),c=read (c),cnt=1;
	scanf ("%s",s+1);
    for (int i=1;i<=n&&cnt<=k;++i)
	{
        if (s[i]=='x')
			continue;
        else
		{
            l[cnt++]=i;
            i+=c;
        }
    }
    cnt=k;
    for (int i=n;i>=1&&cnt;--i)
	{
        if(s[i]=='x')
			continue;
        else
		{
            r[cnt--]=i;
            i-=c;
        }
    }
    for (int i=1;i<=k;++i)
        if (l[i]==r[i]&&l[i]!=-1)
    		printf ("%d\n",l[i]);
	return 0;
}