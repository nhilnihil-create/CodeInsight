#include<stdio.h>
#include<string.h>

typedef long long ll;

int main(){
	char x[105];
	int n;
	scanf("%d",&n);
	getchar();
	scanf("%s",x);
	if(n%2==1){
		printf("No");
		return 0;
	}
	n/=2;
	for(int i=0;i<n;i++){
		if(x[i]!=x[i+n]){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}