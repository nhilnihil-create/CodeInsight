#include <stdio.h>

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	int total = n+m;
	int e = 1, o = 1;
	
	for(int i = 2 ; i < n ; i++){
		e+=i;
	}
	for(int i = 2 ; i < m ; i++){
		o+=i;
	}
	
	if(n == 1 || n == 0){
		e = 0;
	}
	if(m == 1 || m == 0){
		o = 0;
	}
	
	printf("%d", e + o);
	
	return 0;
}