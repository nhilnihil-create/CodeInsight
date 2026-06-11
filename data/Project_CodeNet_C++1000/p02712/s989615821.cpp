#include<stdio.h>

int main(){
	double angka;
	double tempSum=0.0000;
	scanf("%lf", &angka);
	for(long long int i=1;i<=angka;i++){
		double tempI=0;
		if((i%3==0)||(i%5==0)){
			continue;
		}
		else{
			tempI=i/10.000;
			tempSum+=tempI;
		}
		//printf("Hasil angka %lld dengan hasil temp %lf dengan tempI %lf\n", i, tempSum, tempI);
	}
	long long int hasil=tempSum*10;
	printf("%lld\n", hasil);
	return 0;
}