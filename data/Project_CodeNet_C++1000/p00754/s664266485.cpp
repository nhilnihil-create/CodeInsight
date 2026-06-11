#include <stdio.h>
#include <string.h>

#define MAX (1000)

int main(void)
{
	int sp;
	char stack[MAX];
	char str[MAX + 1];
	while (1){
		int i;

		fgets(str, MAX, stdin);
		if (str[0] == '.'){
			break;
		}

		if (str[strlen(str) - 1] == '\n'){
			str[strlen(str) - 1] = '\0';
		}

		sp = 0;
		for (i = 0; str[i] != '\0'; i++){
			if (str[i] == '[' || str[i] == '('){
				stack[sp++] = str[i];
			}
			else if (str[i] == ')' || str[i] == ']'){
				if (sp == 0){
					break;
				}
				char top = stack[--sp];
				if (top == '['){
					top = ']';
				}
				else {
					top = ')';
				}
				if (top != str[i]){
					break;
				}
			}
		}
	
		
		if (i != 0 && str[i] == '\0' && str[i - 1] == '.' && sp == 0){
			puts("yes");
		}
		else {
			puts("no");
		}
	}

	return (0);
}