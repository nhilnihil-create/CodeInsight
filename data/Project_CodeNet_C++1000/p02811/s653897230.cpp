#include<stdio.h>
	int main(){
		int K,X,yen;
		scanf ("%d",&K);
		getchar();
		scanf ("%d",&X);
		getchar();
		yen=500;
		if (K*yen>=X){
			printf ("Yes\n");
		}else {
			printf ("No\n");
		}
		return 0;
	}
