#include <stdio.h>
#include <string.h>

int main() {

 	long long int n;
 	scanf("%lld", &n);
 	
 	char name[20]={};
	n--;
 	for(long long int i=0; n>=0; i++){
		name[i]=(n%26)+'a';
		n/=26;
		n--;	
	 }
	 
  	long long int nn = strlen(name);
	for(long long int i = nn-1; i >= 0; i--){
 	 printf("%c", name[i]);
	}
	
	printf("\n");


    return 0;
}