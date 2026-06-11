#include <stdio.h>



#ifndef DEBUG 
#define fprintf (void)
#endif 

int main(void){

	char word[400];
	char sword[201];
	char trash;
	int i=0;
	int j,k,h;
	int l=0;
	int m;
	int endcount=0;
	
	while(1){
		
		if(l==1){
			scanf("%c",&trash);
		}
		
		while(1){
			scanf("%c",&word[i]);
			if(word[i]=='\n'){
				break;
			}else if(word[i]=='-'){
				endcount=1;
				break;
			}
			i++;
		}
		
		fprintf(stdout,"%d\n",i);
		
		if(endcount==1){
			break;
		}
		
		for(j=i;j<2*i;j++){
			word[j]=word[j-i];
		}
		
		for(k=0;k<2*i;k++){
			fprintf(stdout,"%c",word[k]);
		}
		fprintf(stdout,"\n");
	
		scanf("%d",&m);
		
		for(j=0;j<m;j++){
			scanf("%d",&h);

			for(k=0;k<i;k++){
				if(h>=i){
					sword[k]=word[k];
					fprintf(stdout,"TOO MUCH\n");
				}else{
					sword[k]=word[k+h];
				}
			}
			
			for(k=0;k<i;k++){
			fprintf(stdout,"%c",sword[k]);
			}
			fprintf(stdout,"\nsword recorded\n");
	
			for(k=0;k<i;k++){
				word[k]=sword[k];
				word[k+i]=sword[k];
			}
			
			for(k=0;k<2*i;k++){
			fprintf(stdout,"%c",word[k]);
			}
			fprintf(stdout,"\nEND SHUFFLE\n");
		}
		
		for(j=0;j<i;j++){
			printf("%c",word[j]);
		}
		printf("\n");
		
		i=0;
		j=0;
		k=0;
		l=1;
	}	
	
	
	return 0;
}