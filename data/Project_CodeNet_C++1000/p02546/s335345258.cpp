#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	char s[1003];
	int i,len,k=0;
	scanf("%s",s);
	len=strlen(s);
	if(s[len-1]=='s'){ 
		s[len]='e';
		s[len+1]='s';
		k=1;
	}
	else	s[len]='s';
	if(k==1){
		for(i=0;i<len+2;i++) printf("%c",s[i]);
	}
	else{
		for(i=0;i<=len;i++) printf("%c",s[i]);
	}
	return 0;
}
		