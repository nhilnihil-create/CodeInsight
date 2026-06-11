#include <stdio.h>

int main(void) {
	int n, m, i;
	char t[256];
	char dmy[256];
	while(1){
		for(i = 0;i < 256;i++){
			t[i] = (char)i;
		}
		scanf("%d",&n);
		if(n == 0){
			break;
		}
		gets(dmy);
		for(i = 0;i < n;i++){
			char ch1, ch2;
			ch1 = getchar();
			getchar();
			ch2 = getchar();
			gets(dmy);
			t[ch1] = ch2;
		}
		scanf("%d",&m);
		gets(dmy);
		for(i = 0;i < m;i++){
			char ch;
			ch = getchar();
			gets(dmy);
			printf("%c",t[ch]);
		}
		printf("\n");
	}
	return 0;
}