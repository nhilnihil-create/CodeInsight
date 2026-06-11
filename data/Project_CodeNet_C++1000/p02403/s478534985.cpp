#include<cstdio>

int H, W;

void print_rectangle(){
	for( int i = 1 ; i <= H ; i++ ){
		for( int j = 1 ; j <= W ; j++ ){
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	while(1){
		scanf("%d %d", &H, &W);
		if( H == 0 && W == 0 ) break;

		print_rectangle();
	}

	return 0;
}