#include<cstdio>
#include<cstring>
using namespace std;
char s[1005];
int main(){
	scanf("%s",s);
	printf("%s",s);
	int len=strlen(s);
	if (s[len-1]=='s') printf("es");
	else putchar('s');
	return 0;
}