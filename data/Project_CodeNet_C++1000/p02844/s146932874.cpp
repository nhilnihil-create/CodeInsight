#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	int count = 0;
	for (int i=0;i<1000;i++){
		int c[3] = { i/ 100,(i/10)%10,i%10};
		int f = 0;
		for(int j=0;j<n;j++){
			if(str[j]==('0'+c[f])){
				f++;
			}
			if(f==3){
				break;
			}
		}
		if(f==3){
			count++;
		}
	}
	printf("%d",count);
}