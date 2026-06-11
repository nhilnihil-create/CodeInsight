#include<stdio.h>
using namespace std;

int main(){
	int h, w;
	int i,j,k;
	while(1){
		k=0;
		scanf("%d %d", &h, &w);
		if(!h && !w)break;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if((k%2+j) % 2){
					putchar('.');
				}else{
					putchar('#');
				}
			}
			putchar('\n');
			k++;
		}
		putchar('\n');
	}
	return 0;
}