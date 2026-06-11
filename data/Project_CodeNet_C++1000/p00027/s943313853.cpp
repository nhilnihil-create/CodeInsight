#include <stdio.h>
int main(){
	char day[][16] = {"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
	int month[12] = {30,28,30,29,30,29,30,30,29,30,29,30};
	int m,d,i,n;
	while(1){
		n=0;
		scanf("%d%d",&m,&d);
		if(!m&&!d) break;
		for(i=0;i<m-1;i++) n += month[i]+1;
		n+=d-1;
		n = n%7;
		printf("%s\n",day[n]);
	}
	return 0;
}