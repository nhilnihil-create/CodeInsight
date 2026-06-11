#include<stdio.h>

int main(){
	int t;
	long long a[100010];
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		scanf("%lld", &a[i]);
		if (a[i]==0){
			printf("%d\n", 0);
			return 0;
		}
	}
	long long u=1;
	long long s=1e18;
	for(int i=0; i<t; i++){
			s/=a[i];
			if(s<1){
			printf("%d\n", -1);
			return 0;
			}
			else{
			u*=a[i];
			if(s>=1 && i==(t-1)) {
				printf("%lld\n", u);
				}
			}
			}
		

	
	return 0;
}