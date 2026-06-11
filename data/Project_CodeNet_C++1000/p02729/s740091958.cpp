#include<stdio.h>
#include<string.h>

// helpful functions
#define fl(i,n) for(long long i = 0; i < n; i++)
#define fls(i,a,b) for(long long i = a; i <= b; i ++)
#define afl(i,a,n) int a[n]; for(int i = 0; i < n; i++) scanf("%d", &ar[i])

// printers
#define iprint(x) printf("%d\n", x)
#define lprint(x) printf("%lld\n", x)
#define fprint(x,n) printf("%.nf\n", x)
#define dprint(x,n) printf("%.nlf\n", x)
#define sprint(x) printf("%s\n", x)

// scanners
#define iscan(x) scanf("%d", &x)
#define lcan(x) scanf("%lld", &x)
#define fscan(x) scanf("%f", &x)
#define dscan(x) scanf("%lf", &x)
#define scan(x) scanf("%s", x)
#define qs(x) long long x; scanf("%lld", &x)

int main()
{
	qs(odd); qs(even);
	iprint(odd*(odd-1)/2 + even*(even-1)/2);
	return 0;
}