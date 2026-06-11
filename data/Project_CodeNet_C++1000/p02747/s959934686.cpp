#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char c[105];
int l;

int main(void){
	scanf("%s",c+1);
	int l=strlen(c+1);
	if(l%2==1){
		printf("No\n");
		return 0;
	}
	for(int i=1;i<=l;i++){
		if(i%2==1&&c[i]!='h'){
			printf("No\n");
			return 0;
		}
		else
		if(i%2==0&&c[i]!='i'){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
} 