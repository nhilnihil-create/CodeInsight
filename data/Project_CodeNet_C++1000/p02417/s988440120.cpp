#include<stdio.h>
int main(){
	char kata;
	int val[26]={0};
	while(scanf("%c", &kata)!=EOF){
		if('A'<=kata&& kata<='Z'){
			val[kata-'A']++;
		}
		else if('a'<=kata && kata<='z'){
			val[kata-'a']++;
		}
	}
	for(int i=0; i<26; i++){
		printf("%c : %d\n", 'a'+i, val[i]);
	}
}
