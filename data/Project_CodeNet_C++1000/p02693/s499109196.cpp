#include <stdio.h>
int main (){
	int A, B, K, angka=0;
scanf("%d", &K);
scanf("%d %d", &A, &B);//batas atas batas bawah  
		for (int i=A; i<=B;++i ){//cari tiap angka yang ada di antara batas
			if (i%K ==0){
				
				angka=1;
				break;
				}		
}
angka?printf("OK\n"):printf("NG\n");		
	
	return 0;

		}
		