#include<stdio.h>
#include<string.h>

// helpful functions
#define fl(i,n) for(int i = 0; i < n; i++)
#define fls(i,a,b) for(int i = a; i < b; i ++)
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
#define qs(x) int x; scanf("%d", &x)

int main()
{
	int n; scanf("%d", &n);
	int num[n], count[n] = {0}, u = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		int x, yes = 1;
		scanf("%d", &x);
		for(int j = 0; j < u; j++) 
		{
			if(x == num[j])
			{
				yes = 0;
				count[j]++;
				break;
			}
		}
		if(yes) 
		{
			count[u]++;
			num[u++] = x;
		}
	}
	fls(i,0,u) fls(j,i+1,u) fls(k,j+1,u)
	{
		if(num[i]+num[j]>num[k] && num[i]+num[k]>num[j] && num[k]+num[j]>num[i]) ans += count[i]*count[j]*count[k];
	}
	printf("%d\n", ans);
	return 0;
}