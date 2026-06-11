#include<cstdio>

int main(){
	char s[200];
	char p[100];
	char t ;
	int c = 0;
	scanf("%c", &t);
	while(t - 10){
		s[c] = t;
		c++;
		scanf("%c", &t);
	}

	int a = 0;
	scanf("%c", &t);
	while(t - 10){
		p[a] = t;
		a++;
		scanf("%c", &t);
	}

	for(int i = 0; i < c; i++){
		s[i + c] = s[i];
		int j;
		for(j = 0; j < a; j++){
			if(p[j] - s[j + i]){
				j += a;
			}
		}
		if(j == a){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}