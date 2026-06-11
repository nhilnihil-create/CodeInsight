#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define LL long long
#define swap(x,y) (x^=y^=x^=y)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
LL n,a,b;
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);if(a>b&&swap(a,b),(a&1)==(b&1)) return printf("%lld",b-a>>1),0;
	return printf("%lld",(b-a-1>>1)+min(a,n-b+1)),0;
}