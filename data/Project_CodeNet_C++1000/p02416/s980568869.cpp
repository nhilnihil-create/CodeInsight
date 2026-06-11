#include<cstdio>
#include<cstring>

int main(){
	char X[10000];
	while(1){
		int i,y=0;

		scanf("%s",X);
		if((X[0] == '0')&&(X[1] == '\0')) break;

		for(i=0; i<10000; i++){
			if(X[i] == '\0') break;
			y += X[i] - '0';
		}

		printf("%d\n",y);
	}

	return 0;
}