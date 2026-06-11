#include<stdio.h>
#include<math.h>
int main(void)
{
	int i,j;
	double a,s[1001],d,f,g,h;
	while(1){
		f=0;
		d=0;
		scanf("%lf",&a);
		if(a==0)	break;
		for(i=0;i<a;i++){
			scanf("%lf",&s[i]);
			d+=s[i];
		}
		d=d/a;
		for(i=0;i<a;i++)
			f+=(s[i]-d)*(s[i]-d);
		f=f/a;
		f=sqrt(f);
		printf("%lf\n",f);
	}
	return 0;
}