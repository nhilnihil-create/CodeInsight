#include <bits/stdc++.h>

#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
//#define int LL
using namespace std;
//const int N   = ;
//const int mod = ;
const int INF =numeric_limits<int >::max();
#define For(n) for (int i=1;i<=n;++i)
#define rep(i,n) for (int i=1;i<=n;++i)
#define repp(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int n;
signed main()
{
	read(n);int tmp=gcd(360,n);
	tmp=360*n/tmp;
    printf("%d",tmp/n);

}

