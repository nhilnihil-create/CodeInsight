#include <stdio.h>

int main(){
	int x,y,t=1;
	scanf("%d",&x);
	char a[x+1];
	scanf("%s",a);
	if(x%2==1){
		puts("No");
	}
	else{
		int t=1;
		for(int i=0;i<x/2;i++){
			if(a[i]!=a[i+x/2]){
				t-=1;
			}
		}
		if(t==0){
		puts("No");	
		}
		if(t==1){
		puts("Yes");
	}
}

	return 0;
}
	