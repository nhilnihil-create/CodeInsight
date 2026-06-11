#include<cstdio>

int main(){
	char str[1001];
	char com[8];
	int l = 0;
	int a, b;
	int q;
	char c;
	scanf("%s", &str);
	
	scanf("%d", &q);

	for(int i = 0; i < q ; i++){
		scanf("%s %d %d", &com, &a, &b);
		if(com[2] == 'i'){
			for(int i = a; i <= b; i++){
				printf("%c", str[i]);
			}
			printf("\n");
		}else if(com[2] == 'v'){
			char t;
			for(int i = 0; i < ((b - a + 1) / 2); i++){
				t = str[a + i];
				str[a + i] = str[b - i];
				str[b - i] = t;
			}
		}else{
			char r[1001];
			scanf("%s", &r);
			for(int j = a; j <= b; j++){
				str[j] = r[j - a];
			}
		}
	}
	return 0;
}