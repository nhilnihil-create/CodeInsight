#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<map>
#include<stack>
#include<set>
#include<functional>
#define in(x) x=read()
#define qr read()
#define int ll
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline ll read()
	{
        bool sign=0; char ch=nc();ll x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n=qr;
	int po=1;
	while(po<n)po*=2;
	if(po==n)return puts("No"),0;
	po/=2;
	puts("Yes");
	for(int i=2;i<n;i+=2)
	{
		cout<<"1 "<<i<<'\n'<<i<<" "<<i+1<<'\n'<<"1 "<<n+i+1<<"\n"<<n+i+1<<" "<<n+i<<'\n'; 
	}
	if(n%2==0)
	{
		cout<<(n^po)<<" "<<(n<<1)<<"\n"<<((po^1)+n)<<' '<<n<<'\n';
		cout<<"3 "<<n+1;
	}
	else
	{
		cout<<"3 "<<n+1;
	}
	return 0;
}