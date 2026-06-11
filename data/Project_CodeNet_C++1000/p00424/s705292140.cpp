#include <stdio.h>
int main(){
	int n,i,j,m,f;
	char a[256],b[256],x;
	while(1){
	scanf("%d ",&n);
	if(n==0){
		break;
        }

	for(i=0;i<n;i++){
		scanf("%s %s ",&a[i],&b[i]);
	}
	
	scanf("%d ",&m);
	for(i=0;i<m;i++){
		scanf("%s",&x);
		f=0;
		for(j=0;j<n;j++){
		 if(x==a[j]){
			printf("%c",b[j]);
			f=1;
			break;
		 }
	    }
	 if(f==0){
	    printf("%c",x);
	 }
	}
		printf("\n");
	}
	return 0;
}