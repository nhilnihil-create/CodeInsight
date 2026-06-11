#include <stdio.h>
#include <cctype>

int main(void){

	char word[11]="0000000000";
	char t[11]="0000000000";
	char end[]="END_OF_TEXT";
	int i=0;
	int j=0;
	int k;
	int ans=0;
	int count=0;
	int endcount=1;
	
	while(1){
		scanf("%c",&word[i]);
		
		if(word[i]=='\n'){
			break;
		}
		
		if(islower(word[i])){
			word[i]=toupper(word[i]);
		}
		
		i++;
	}
	
	while(1){
		while(1){
			scanf("%c",&t[j]);
			
			if(t[j]=='\n'||t[j]==' '){
				break;
			}

			j++;
		}
		
		for(k=0;k<11;k++){
			if(t[k]!=end[k]){
				endcount=0;
			}
		}
		
		if(endcount==1){
			break;
		}
		
		endcount=1;
		
		for(k=0;k<j;k++){
			if(islower(t[k])){
				t[k]=toupper(t[k]);
			}
			
			if(t[k]==word[k]){
				ans++;
			}else{
				ans=0;
			}
		}
		
		if(ans==i&&(t[j]=='\n'||t[j]==' ')){
			count++;
		}
		
		ans=0;
		
		j=0;
	}
	
	printf("%d\n",count);
	
	return 0;
}