#include<stdio.h>
#include<string.h>
int main(){
	int index;
	scanf("%d", &index);
	char string[index+2];
	scanf("%s", &string);
	if(index%2==1){
		printf("No");
	}
	else{
		int flag=1;
		int i=0,j=0;
		for(i=0;i<=(index/2)-1;i++){
			j=(index/2)+i;
			if(string[i]==string[j]){
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}
		flag==1? printf("Yes\n"):printf("No\n");
	}
	return 0;
}