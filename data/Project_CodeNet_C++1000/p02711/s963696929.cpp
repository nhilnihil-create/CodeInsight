#include <stdio.h>
 
int main (){
	int i;
	scanf ("%d", &i);
	
	int num1 = i / 100;
	int num2 = (i / 10) % 10;
	int num3 = i % 10;
	
	while (i > 0){
		if (num1 == 7) {
			printf ("Yes");
			break;
		}
		else if (num2 == 7){
			printf ("Yes");
			break;
		}
		else if (num3 == 7){
			printf ("Yes");
			break;
		}
		else{
			printf ("No");
			break;
		}
	}
	return 0;
}