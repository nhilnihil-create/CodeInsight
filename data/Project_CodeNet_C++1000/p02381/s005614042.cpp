#include<cstdio>
#include<cmath>

int main(void){
int n,i,k=0;
double h[256];
while(1){
	scanf("%d",&n);
	if(n==0) break;
	double s[n],sum=0,average,bunsan=0;

	for(i=0;i<n;i++){
		scanf("%lf",&s[i]);
		sum=sum+s[i];
	}
	average=sum/n;
	for(i=0;i<n;i++){
		bunsan=bunsan+(s[i]-average)*(s[i]-average);
	}
	bunsan=bunsan/n;
	h[k]=sqrt(bunsan);
	k++;
}
for(i=0;i<k;i++){
	printf("%f\n",h[i]);
}
return 0;
}

		