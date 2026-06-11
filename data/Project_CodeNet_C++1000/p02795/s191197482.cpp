#include<stdio.h>

int main(){
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	int ctr=0, tot=0;
	while(1){
		if(((1*w)>=(1*h)) && tot<n){
			ctr++;
			tot+=(1*w);
		}
		else if(((1*h)>(1*w)) && tot<n){
			ctr++;
			tot+=(1*h);
		}
		else{
			break;
		}
	}
	printf("%d", ctr);
	return 0;
}