#include <stdio.h>
#include <string.h>

int main(){
 	int k;
 	char a[100];
 	scanf ("%d", &k);
 	scanf ("%s", a);
 	
 	if (strlen(a) <= k) {
  		printf ("%s", a);
	} 
 	else {
  		for(int i = 0; i < k; i++) {
   			printf ("%c", a[i]);
  		}
  		printf ("...");
 	}
	return 0;
}