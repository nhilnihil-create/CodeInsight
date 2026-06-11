#include <stdio.h>

int main(void)
{
	int n,m,i;
	
	while(scanf("%d",&n),n){
		
		char data[10000000],afch[200]={0};
		bool bech[200]={0};
		char temp,str[5];
		
		for(i=0;i<n;i++){
			scanf("%s",str);
			temp=str[0];
			bech[temp-48]=1;
			scanf("%s",str);
			afch[temp-48]=str[0];
		}
		
		scanf("%d",&m);
		
		for(i=0;i<m;i++){
			scanf("%s",str);
			data[i]=str[0];
		}
		for(i=0;i<m;i++){
			if(bech[data[i]-48]==1)printf("%c",afch[data[i]-48]);
			else printf("%c",data[i]);
		}
		puts("");
	}
	
	return 0;
}