#include <stdio.h>
#include <string.h>

int main(){
	int lg;
	scanf ("%d", &lg);
	char word[lg+1];
	int st1 = 0;
	int st2 =lg/2;
	int wall = st2-1;
	scanf ("%s", word);
	
	if (lg % 2 != 0){
		printf ("No\n");
		return 0;
	}
	
	for (int i=0; i<=wall; i++){
		if (word[st1+i] == word[st2+i]){
			continue;
		}
		else {
			printf ("No\n");
			return 0;
		}
	}
	
	printf ("Yes\n");
return 0;
}