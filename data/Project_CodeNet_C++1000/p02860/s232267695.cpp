#include <stdio.h>

// abcabc
// 012345

int main (){
	int t; 
	scanf("%d", &t);
	char huruf[t+1];
	scanf("%s", &huruf);
	if (t%2==1){
		printf("No\n");
	}
	else{
		int counter = 1;
		for (int i=0; i<t/2; i++){
			if (huruf[i]!= huruf[i+ t/2]){
				counter =0;
			}
		}
		if (counter){
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	
	return 0;
}