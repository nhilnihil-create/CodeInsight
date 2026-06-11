#include <stdio.h>
int main(){
	
    int input;
	long long int count = 0;
	scanf("%d", &input);
	
    for (int i = 1; i <= input; i++){
		if (i % 3 == 0 && i % 5 == 0){
		}
        else if (i % 3 == 0){	
		}
        else if (i % 5 == 0){
		}
        else {count += i;}
	}
	printf("%lld\n", count);
	
    return 0;
}