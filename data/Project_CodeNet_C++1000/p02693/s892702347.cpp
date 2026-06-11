#include <stdio.h>

int main (){
	
	int perkalian, num1, num2;
	scanf ("%d\n", &perkalian);
	scanf ("%d %d", &num1, &num2);
	int hasil;
	hasil = (num2/perkalian)*perkalian;
	if (hasil>=num1){
		printf ("OK");
	}
	else
		printf("NG");

	return 0;
}