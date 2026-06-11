#include <stdio.h>
int main(){
	//soal F
	long long int N; //test case
	long long int g = 1; //buat hasil perkalian
	scanf("%lld", &N);
	long long int h[N]={}; //array buat menampung angka

		for(long long int i=0;i<N;i++){
			scanf("%lld", &h[i]);  
		} 
		for(int j=0;j<N;j++){
			if (h[j] == 0){
	 			printf("0");
 				return 0;
			}
		}
		for(int k=0;k<N;k++){
 			if (h[k] <= 1000000000000000000/g){
 			g *= h[k];
		} else {
			printf("-1");
			return 0;
		}
	}	
		printf("%lld",g);
	return 0;
}
/*
cek inputan sekarang dia > 10^18
inputan ->10^18 / total

long long tc;
long long hasil = 1;
scanf("%lld", &n);

long long input[tc];
for (int i=0;i<tc;i++){
scanf("%lld", input)
}

for(int i=0;i<tc;i++){
 if (input[i] == 0){
 		printf("0");
 		return 0;
}
for(int i=0;i<tc;i++){
 if (input[i] > 1000000/hasil){
 		hasil *= input[i]
} else {
	}

*/