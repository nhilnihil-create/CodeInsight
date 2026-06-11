#include <stdio.h>
#include <string.h>

const char word[9][6] = {{".,!? "},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
const char len[9] = {5,3,3,3,3,3,4,3,4};
int main(void){
	char str[1025], tmp;
	int n, i, j, count;
	scanf("%d%*c",&n);
	for(i = 0;i < n;i++){
		gets(str);
		str[strlen(str)] = '\0';
		j = 0;
		while(str[j] != '\0'){
			tmp = str[j];
			if(tmp != '0'){
				count = 1;
				while(str[++j] == tmp)
					count++;
				putchar(word[tmp - '1'][(count - 1) % len[tmp - '1']]);
			}
			else
				j++;
		}
		printf("\n");
	}
	return 0;
}