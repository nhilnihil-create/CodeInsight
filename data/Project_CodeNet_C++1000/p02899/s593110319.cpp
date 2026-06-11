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

int n;
struct node {
	int num,pos;
}a[N];

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
bool cmp(node x,node y) {return x.num<y.num;}

signed main()
{
	n=read();
	Rf(i,1,n) {
		a[i].num=read();a[i].pos=i;
	}
	sort(a+1,a+1+n,cmp);
	Rf(i,1,n) {
		write(a[i].pos);putchar(' ');
	}

    return 0;
}
