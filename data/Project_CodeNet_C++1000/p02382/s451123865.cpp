#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	int i,x[100],y[100],n;
	double p_1=0.0,p_2=0.0,p_3=0.0,p_inf=0.0;
	char input[512],*p;
	
	fgets(input,sizeof input,stdin);
	sscanf(input,"%d",&n);
	
	fgets(input,sizeof input,stdin);
	p=strtok(input," ");
	x[0]=atoi(p);
	for(i=1;i<n;i++){
		p=strtok(NULL," ");
		x[i]=atoi(p);
	}
	
	fgets(input,sizeof input,stdin);
	p=strtok(input," ");
	y[0]=atoi(p);
	for(i=1;i<n;i++){
		p=strtok(NULL," ");
		y[i]=atoi(p);
	}
	
	for(i=0;i<n;i++){
		p_1+=fabs((double)x[i]-(double)y[i]);
		p_2+=pow(fabs((double)x[i]-(double)y[i]),2);
		p_3+=pow(fabs((double)x[i]-(double)y[i]),3);
		
		if(p_inf<=fabs((double)x[i]-(double)y[i])){
			p_inf=fabs((double)x[i]-(double)y[i]);
		}
		
	}
	p_2=sqrt(p_2);
	p_3=cbrt(p_3);
	
	printf("%f\n%f\n%f\n%f\n",p_1,p_2,p_3,p_inf);
	
	return 0;
}