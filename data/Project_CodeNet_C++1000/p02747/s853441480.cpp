#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

char str[15];

int main(){
	scanf("%s", str);
	int len = strlen(str);
	if(len % 2 != 0){
		printf("No\n");
	}else{
		for(int i = 0; i < len; i += 2){
			if(str[i] != 'h' || str[i + 1] != 'i'){
				printf("No\n");
				return 0;
			}
		}
		printf("Yes\n");
	}
}