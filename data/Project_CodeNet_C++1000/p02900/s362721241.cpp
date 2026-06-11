#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<ctime>

#define int long long
#define R register
#define IL inline
#define Rf(a,b,c) for(R int (a)=(b);(a)<=(c);++(a))
#define Tf(a,b,c) for(R int (a)=(b);(a)>=(c);--(a))
#define MP make_pair
#define PA pair<int,int>
#define MES(a,b) memset((a),(b),sizeof((a)))
#define MEC(a,b) memcpy((a),(b),sizeof((b)))
#define D double

using namespace std;

const int N=1e6+5;

int A,B,ans,cnt,prim[N],vis[N];
  
IL int read() {
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x*=10;x+=(ch-'0');ch=getchar();}
    return x*f;
}
IL void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int gcd(int x,int y) {return x%y?gcd(y,x%y):y;}
void getp(int n)
{
    Rf(i,2,n) {
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;j<=cnt&&prim[j]*i<=n;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
}

signed main()
{
	A=read();B=read();
	int g=gcd(A,B);
	getp(N-5);
	for(R int i=1;i<=cnt&&prim[i]<=g;++i) {
		if(g%prim[i]==0) {
			ans++;
			while(g%prim[i]==0) g/=prim[i];
		}
	}
	if(g!=1) ans++;
	write(ans+1);
	
	
    return 0;
}
