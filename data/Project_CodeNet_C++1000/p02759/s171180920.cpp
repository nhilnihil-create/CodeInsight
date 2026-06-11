#include<stdio.h>
int main()
{
	int N;
  int hasil;
	scanf("%d", &N);

	if(N%2!=0){
    hasil=N/2;
		printf("%d", hasil+1);
	}
  else{
    hasil=N/2;
    printf("%d", hasil);
  }
	return 0;
}