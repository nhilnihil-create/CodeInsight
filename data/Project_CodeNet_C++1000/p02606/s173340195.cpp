#include <stdio.h>
int main(){
	int l, r, d;
	scanf("%d %d %d", &l, &r, &d);
	int temp=d;
	int sum=0;
	while(temp<=r){
		if(temp>=l){
			sum++;
		}
		temp+=d;
	}
	printf("%d", sum);
	return 0;
}
