#include<stdio.h>
#include<math.h>

int main(void)
{
	int n,k;
	int s[1024];
	double h[1024],x,bak=0,y[1024],t=0;
	for(int j=0;;j++){
		bak=0;
		t=0;
		scanf("%d",&n);
		if(n==0){
			k=j;
			break;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&s[i]);
			y[i]=s[i];
			t+=y[i];
		}
		x=(double)t/(double)n;
		for(int i=0;i<n;i++){
			bak+=(y[i]-x)*(y[i]-x);
		}
		h[j]=sqrt((double)bak/(double)n);
	}
	for(int i=0;i<k;i++){
		printf("%8lf\n",h[i]);
	}
    return 0;
}