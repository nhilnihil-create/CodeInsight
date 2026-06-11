#include<stdio.h>
#include<math.h>
int main(void){
	
	double answer,px,py,p2x,p2y,tate,yoko;
	scanf("%lf %lf %lf %lf",&px,&py,&p2x,&p2y);
	if(py<p2y){
		tate=p2y-py;
	}else if(p2y<py){
		tate=py-p2y;
	}else{
		tate=0;
	}
		if(px<p2x){
	yoko=p2x-px;
		}else if(p2x<px){
	yoko=px-p2x;
		}else{
	yoko=0;
	}
	answer=pow(tate,2)+pow(yoko,2);
	printf("%f",sqrt(answer));
return 0;
}