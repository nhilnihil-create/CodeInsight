#include <stdio.h>

int main(){
	
	int menor, medio, maior, a,b,c;

	
	scanf("%d", &a);

	scanf("%d", &b);
	
	scanf("%d", &c);
	
	if(a == b && c > a){
		menor = a;
		medio = b;
		maior = c;
	}
	
	
	if(a == c && b > a){
		menor = a;
		medio = c;
		maior = b;
	}
	
	
	if(b == c && a > b){
		menor = b;
		medio = c;
		maior = a;
	}
	
	
	if(a < b && a < c){
		menor = a;
		
		if(b < c){
			medio = b;
			maior = c;
		}
			
		if(c < b){
			medio = c;
			maior = b;
		}
		
		if(c == b){
			medio = c;
			maior = b;
		}
		
	}
		
	if(b < a && b < c){
		menor = b;
		
		if(a < c){
			medio = a;
			maior = c;
		}
			
		if(c < a){
			medio = c;
			maior = a;
		}
		
		if(c == a){
			medio = b;
			maior = a;
		}
		
	}
		
	if (c < a && c < b){
		menor = c;
		
		if(a < b){
			medio = a;
			maior = b;
		}
			
		if(b < a){
			medio = b;
			maior = a;
		}
		
		if(b == a){
			medio = b;
			maior = a;
		}
	}
	
	printf("%d %d %d\n", menor, medio, maior);
	
	return 0;
}