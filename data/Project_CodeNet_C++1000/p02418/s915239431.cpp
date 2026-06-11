#include<cstdio>
#include<cstring>
int main(void){
	char a[210];
	int b;
	char c[110];
	int d;
	int z;
	for (int i = 0; i < 210; i++)a[i] = 0;
	for (int i = 0; i < 110; i++)c[i] = 0;
	scanf("%s", a);
	scanf("%s", c);
	b = strlen(a);
	d = strlen(c);
	for (int i = 0; i < b; i++)a[b + i] = a[i];
	for (int i = 0; i < b; i++){
		z = 0;
		for (int j = 0; j < d; j++){
			if (a[i + j] != c[j]){
				z = 1;
				break;
			}
		}
			if (z == 0){
				printf("Yes\n");
				return 0;
			}
	}
	printf("No\n");
	return 0;
}