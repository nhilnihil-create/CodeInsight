#include <stdio.h>
 
int main(){
	
int n;
scanf ("%d", &n);
 
int bilangan = 0;
 // harus dibawah 10 
for (int i = 1; i < 10; i++){ // bilanagn yang pertama
	for (int j = 1; j < 10; j++){ // bilangan yang ke -2 
		
		if (n == i * j){
			bilangan = 1;
			break;
		}
}
/* If N can be represented as the product of two integers between 1 and 9 (inclusive), print Yes; if it cannot, print No.
 */
	}
	if (bilangan == 1){
		puts ("Yes");
	}
	else if (bilangan == 0) {
		puts ("No");
	}
	return 0;
}