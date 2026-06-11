#include<cstdio>
#include<cmath>

int main(void){
int n,i;
scanf("%d",&n);
double x[n],y[n],a[n];
for(i=0;i<n;i++){
	scanf("%lf",&x[i]);
}
for(i=0;i<n;i++){
	scanf("%lf",&y[i]);
}
for(i=0;i<n;i++){
	a[i]=fabs(x[i]-y[i]);
}

double d1=0;
for(i=0;i<n;i++){
	d1=d1+a[i];
}

double d2=0;
for(i=0;i<n;i++){
	d2=d2+(a[i]*a[i]);
}
d2=sqrt(d2);

double d3=0;
for(i=0;i<n;i++){
	d3=d3+(a[i]*a[i]*a[i]);
}

double j;
j=1.0/3.0;
d3=pow(d3,j);

double d4=a[0];
for(i=1;i<n;i++){
	if(d4<a[i]){
		d4=a[i];
	}
}
		
printf("%f\n%f\n%f\n%f\n",d1,d2,d3,d4);

return 0;
}

		