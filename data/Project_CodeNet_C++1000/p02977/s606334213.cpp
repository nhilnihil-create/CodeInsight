#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double db;
const int oo=2139063143;
const int N=1010000;
const int P=1000000007;
const db eps=1e-7;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
    if (x< 0) putchar('-'),x=-x;
    if (x>=10) print(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
template <typename T1,typename T2>
void chkmax (T1 &A,T2 B) { A=A>=B?A:B; }
template <typename T1,typename T2>
void chkmin (T1 &A,T2 B) { A=A<=B?A:B; }


int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	int n; sc(n);
	int k=log2 (n);
	if ((1<<k)==n) return puts("No"),0;
	puts("Yes");
	for (int i=2; i< n; i+=2)
		printf ("%d %d\n%d %d\n%d %d\n%d %d\n",1,i,i,i+1,1,n+i+1,n+i+1,n+i);
	printf ("%d %d\n",n+1,3);
	if (!(n&1)) printf ("%d %d\n%d %d\n",n+(1<<k)+1,n,n-(1<<k),n<<1);

    return 0;
}
