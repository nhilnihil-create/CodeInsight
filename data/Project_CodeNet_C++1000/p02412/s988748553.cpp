#include <stdio.h>

int GetCombination(int n, int x)
{	
	int count = 0;
	for(int i = 1; i <= n - 2; i++){
		for(int j = i + 1; j <= n - 1; j++){
			for(int k = j + 1; k <= n; k++){
				if(i + j + k == x){
					count++;
				} 
			}
		}
	}
	return count;
}

int main(void)
{
	int n, x;
	
	while(true){
	
		scanf("%d %d", &n, &x);
	
		if(n == 0 && x == 0){
			break;
		}
		
		printf("%d\n", GetCombination(n, x));
	}
}