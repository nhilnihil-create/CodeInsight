#include<stdio.h>

int main(){
	int geser;
	char t[10010];
	scanf("%d", &geser);
	scanf("%s", t);
	for (int i=0 ; t[i] != '\0' ; i++){
		t[i]+= geser;
		if (t[i]>'Z'){
			t[i]-=26;
		}
		printf("%c", t[i]);
	}
	puts("");
	return 0;
}