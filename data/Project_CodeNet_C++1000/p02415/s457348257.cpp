#include <stdio.h>
#include <math.h>
#include <string.h>
#define rep(i,a,n) for(int i=a;i<n;i++)

char change(char c){
	char r=c;
	if('a'<=c && c<='z') r+='A'-'a';
	if('A'<=c && c<='Z') r+='a'-'A';
	return r;
}

int main(){
	int len;
	char s[1210];
	gets(s);
	len=strlen(s);
	rep(i,0,len){
		s[i]=change(s[i]);
	}
	printf("%s\n",s);
	return 0;
}