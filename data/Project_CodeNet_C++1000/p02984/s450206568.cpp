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

#define ll long long
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

const int N=1e5+5;

int a[N],b[N],p,n;

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

signed main()
{
	n=read();
	Rf(i,1,n) {
		a[i]=read();
		if(p) b[1]-=a[i];
		else b[1]+=a[i];
		p^=1;
	}
	write(b[1]);
	Rf(i,2,n) {
		putchar(' ');
		b[i]=a[i-1]*2-b[i-1]/2*2;
		write(b[i]);
	}

    return 0;
}
