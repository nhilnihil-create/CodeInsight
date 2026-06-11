#include<stdio.h>
using namespace std;

int main(){
	int h, w;
	int i,j;
	while(1){
		scanf("%d %d", &h, &w);
		if(!h && !w)break;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				putchar('#');
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}