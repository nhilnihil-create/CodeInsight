#include<cstdio>
#include<cstring>

int main(){
	
	char s[100];
	char p[99];
	char ss[10000];
	
	scanf("%s %s", s,p);
	strcpy(ss,s);
	strcat(ss,s);
	if (strstr(ss, p)) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}