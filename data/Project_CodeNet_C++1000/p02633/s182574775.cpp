#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
int x;
inline int gcd(CI x,CI y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	return scanf("%d",&x),printf("%d",360/gcd(x,360)),0;
}