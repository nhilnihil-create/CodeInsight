#include <stdio.h>

int main() {
  	
  	char S[3];
  	scanf("%s", &S);
  	
  	if(S[1] == 'B'){
  		S[1]='R';
	  }
	  else {
	  	S[1]='B';
	  }
  	
  	printf("%s\n", S);

    return 0;
}
