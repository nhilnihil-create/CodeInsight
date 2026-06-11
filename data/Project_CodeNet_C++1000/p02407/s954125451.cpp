#include<stdio.h>
int main(){
	int cs;
	int ang[105];
	scanf("%d", &cs);
	for(int i=0; i<cs; i++){
		scanf("%d", &ang[i]);
	}
	for(int j=cs-1; j>=0; j--){
		if(j==0) printf("%d\n", ang[j]);
		else printf("%d ", ang[j]);
	}
}
