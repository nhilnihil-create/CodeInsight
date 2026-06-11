#include <stdio.h>
int main (){
	int a;
	long long int jumlah = 0;
	scanf ("%d", &a);
	for (int i = 1; i<=a; i++){
		if (i%3 == 0 && i%5==0){
			continue;
		}else if (i%3==0){
			continue;
		}else if(i%5==0){
			continue;		
		}else{
			jumlah+=i;
		}
	}
	printf("%lld\n", jumlah);
	return 0;
}