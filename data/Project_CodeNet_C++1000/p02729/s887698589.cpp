#include<stdio.h>

int main()
{
	int n, m, pass[1005], temp1 = 2, temp2 = 1, idx = 0, ans, ctr = 0;
	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		pass[idx++] = temp1;
		temp1 += 2;
	}
	for(int i = 0; i < m; i++){
		pass[idx++] = temp2;
		temp2 += 2;
	}
	
	for(int i = 0; i < n + m; i++){
		for(int j = i; j < n + m; j++){
			if(i != j){
				ans = pass[i] + pass[j];
				if(ans % 2 == 0){
					++ctr;
				}
			}
		}
	}
	if(ctr == 0){
		printf("0\n");
	}else{
		printf("%d\n", ctr);
	}
}