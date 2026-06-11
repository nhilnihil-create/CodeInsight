#include <cstdio>
#include <cmath>
main(){
	double a,b,c,d,e,f,g,h;
	for(scanf("%lf",&a);~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);)
		puts(fabs((c-a)*(h-f)-(d-b)*(g-e))>1e-10?"NO":"YES");
	return 0;
}